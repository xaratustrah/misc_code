%
% Electrical Engineering and Information Technology
% Department of High Frequency Electronics
% xaratustra FEB 2009
% 
% This script can open multiple S2P files and extract the Transistor
% parameters from it. Then writes the results of those multiple files
% in a single spreadsheet (XLS) file.
%
% This script expects input filesnames in form of e.g. P2F2003xD24_g_-5d_6.s2p
% Multiple filenames could be selected in the standard file choose dialog using
% CTRL or SHIFT key or their combination. The resulting spreadsheet file will
% be stored in the same directory.
%
% The expected input file format is
% ! FILE NAME
% ! DATE 09/19/2006  10:08
% ! CORRECTED   DATA
% # GHz    S       MA      R    50.00
% !   FREQ       S11M         S11A     S21M         S21A      S12M        S12A      S22M        S22A
% 0.100000000 9.812679E-01   -4.155 2.068444E+00  175.442 7.906027E-03   77.962 7.478872E-01   -3.409
% 0.150000000 9.759785E-01   -6.108 2.057307E+00  173.812 1.159828E-02   76.688 7.398815E-01   -4.402
% 0.200000000 9.705002E-01   -7.947 2.041210E+00  172.279 1.500124E-02   76.434 7.353702E-01   -5.517
% .......     .......        .....  .......       .....   .......        .....  .......        .....
% .......     .......        .....  .......       .....   .......        .....  .......        .....
%
% ----
% TODO:
% none.
%

clear;
clc;
dir_name = uigetdir();

if dir_name==0 % user quitted
    fprintf('User aborted...\n');
    return
end

files=dir([dir_name,'\*.s2p']);
pathname = strcat(dir_name, '\');

if isequal(files,0)
    disp('NO DATA FILE IN THIS FOLDER!\n');
    return
end

disp(strcat('Processing S2P files in-->',pathname));
% set the spreadsheet filename
spreadsheet_filename = char(strtok(files(1,1).name,'_'));

for j=1:1:length(files)

    fname{j}=files(j).name; % each file name
    file_handle=fopen(strcat(pathname,files(j,1).name),'rt');
    fgetl(file_handle); %! FILE NAME
    fgetl(file_handle); %! DATE 09/18/2006  09:18
    fgetl(file_handle); %! CORRECTED   DATA
    fgetl(file_handle); %# GHz    S       MA      R    50.00
    fgetl(file_handle); % Column headers

    % freq S11M S11A S21M S21A S12M S12A S22M S22A
    sp=fscanf(file_handle,'%e',[9 inf]);

    %convert to rectangular and store
    s11 = complex(sp(2,:).*cosd(sp(3,:)),sp(2,:).*sind(sp(3,:)));
    s21 = complex(sp(4,:).*cosd(sp(5,:)),sp(4,:).*sind(sp(5,:)));
    s12 = complex(sp(6,:).*cosd(sp(7,:)),sp(6,:).*sind(sp(7,:)));
    s22 = complex(sp(8,:).*cosd(sp(9,:)),sp(8,:).*sind(sp(9,:)));

    %forward current gain in dB
    %Some sources use a multiplier of -1 in the numerator of the expression
    %used for the calculation of the forwad current gain. But -2 is the
    %correct multiplier.
    h21(1,:) = 20 .* log10 ( abs ( (-2.*s21(1,:)) ./ ( (1.-s11(1,:)).*(1.+s22(1,:))+(s12(1,:).*s21(1,:)) ) ) );

    %----------------------------
    % find ft
    found_ft = false;
    for i=1:size(h21,2)
        if h21(1,i) <= 0
            ft=sp(1,i);
            found_ft = true;
            break;
        else
            % keep variable false, but continue checking for a point.
            found_ft = false;
        end
    end

    % now if there were no frequencies in the table which corresponded to
    % h21=0, then extrapolate to find the value.
    if found_ft == false
        x1 = log10(sp(1,i));
        y1 = h21(1,i);
        m = -20;
        x = 8:.1:9;
        y = m .* (x - x1) + y1;
        ft = 10^(interp1(y, x, 0, 'linear', 'extrap'));
        disp(strcat(files(j,1).name, ': Using extrapolated value for f_T...'));
    end
    %----------------------------
    %stability factor
    K(1,:) =  (1 + (abs( s11(1,:) .* s22(1,:) - s12(1,:) .* s21(1,:) ).^2) - sp(2,:).^2 - sp(8,:).^2 ) ./ (2 .* sp(6,:) .* sp(4,:) ) ;

    %----------------------------
    % find Max. gain in dB
    for i=1:length(K)
        if K(1,i) > 1
            MG(1,i) = 10 .* log10( sp(4,i) .* ( K(1,i) - ( K(1,i).^2 - 1 ).^0.5 ) ./ sp(6,i) );
        else
            MG(1,i) = 10 .* log10( sp(4,i) ./ sp(6,i) );
        end
    end

    %----------------------------
    %find Fmax with regard to Gmax
    found_Fmax_Gmax = false;
    for i=1:size(MG,2)
        if MG(1,i) <= 0
            fmax_Gmax=sp(1,i);
            found_Fmax_Gmax = true;
            break;
        else
            % keep variable false, but continue checking for a point.
            found_Fmax_Gmax = false;
        end
    end
    if found_Fmax_Gmax == false
        x1 = log10(sp(1,i));
        y1 = MG(1,i);
        m = -20;
        x = 8:.1:9;
        y = m .* (x - x1) + y1;
        fmax_Gmax = 10^(interp1(y, x, 0, 'linear', 'extrap'));
        disp(strcat(files(j,1).name, ': Using extrapolated value for fmax_Gmax...'));
    end
    %----------------------------
    % find Max. unilateral transducer gain in dB

    MUG(1,:) = 10 .* log10( sp(4,:).^2 ./ ( (1 - sp(2,:).^2  ) .* (1 - sp(8,:).^2 ) ) );

    %----------------------------
    %find Fmax with regard to Gu
    found_FGu = false;
    for i=1:size(MUG,2)
        if MUG(1,i) <= 0
            fmax_Gu=sp(1,i);
            found_FGu = true;
            break;
        else
            % keep variable false, but continue checking for a point.
            found_FGu = false;
        end
    end
    if found_FGu == false
        x1 = log10(sp(1,i));
        y1 = MUG(1,i);
        m = -20;
        x = 8:.1:9;
        y = m .* (x - x1) + y1;
        fmax_Gu = 10^(interp1(y, x, 0, 'linear', 'extrap'));
        disp(strcat(files(j,1).name, ': Using extrapolated value for Fmax_Gu...'));
    end
    % Now extract the Vg and Vd from the file name:
    current_file_name= char(files(j,1).name);
    vg = str2double(current_file_name(strfind(current_file_name, '_g_') + 3 : strfind(current_file_name, 'd_') - 1));
    vd = str2double(current_file_name(strfind(current_file_name, 'd_') + 2 : strfind(current_file_name, '.s2p') - 1));

    fclose(file_handle);

    % add the calculated information to the spread sheet
    spreadsheet_content(j,:) = [vg vd ft fmax_Gmax fmax_Gu];
end;

%spreadsheet_content

% Write the data to the spreadsheet file.
% This works only if MS Excell is installed on the system.
% At the runtime, close all MS Excell instances


xlswrite (strcat(pathname, spreadsheet_filename), {'V_g','V_d','f_T','F_maxGmax','F_maxGu'}, 1);
xlswrite(strcat(pathname, spreadsheet_filename), spreadsheet_content, 1, 'a2');
disp('Done.');
