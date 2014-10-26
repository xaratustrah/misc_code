%
% Electrical Engineering and Information Technology
% Department of High Frequency Electronics
% xaratustra FEB 2009
% 
% This script can open multiple S2P files and extract the Diode
% S-parameters from it. Then writes the results of those multiple files
% in a single spreadsheet (XLS) file.
%
% This script expects input filesnames in form of e.g. 211c11_Bias=0.0.s2p
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

% Put desired frequency here:
desired_frequency = 0.631250000;

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

    %----------------------------
    % find frequency
    
    found_freq = false;
    for i=1:size(sp',1)
        if sp(1,i)== desired_frequency
            s11_m = sp(2,i);
            s11_a = sp(3,i);
            s11_re = sp(2,i).*cosd(sp(3,i));
            s11_im = sp(2,i).*sind(sp(3,i));
            found_freq = true;
            break;
        else
            % keep variable false, but continue checking for a point.
            found_freq = false;
        end
    end
        
    % Now extract the Vbias from the file name:
    current_file_name= char(files(j,1).name);
    vbias = str2double(current_file_name(strfind(current_file_name, 'Bias=') + 5 : strfind(current_file_name, '.s2p') - 1));

    fclose(file_handle);

    if found_freq == false
        break;
    end
    % add the calculated information to the spread sheet
    spreadsheet_content(j,:) = [vbias desired_frequency s11_m s11_a s11_re s11_im];
end;

%spreadsheet_content

% Write the data to the spreadsheet file.
% This works only if MS Excell is installed on the system.
% At the runtime, close all MS Excell instances

if found_freq == true 
    xlswrite (strcat(pathname, spreadsheet_filename), {'Vbias [V]','Frequency [GHz]','S11 Mag', 'S11 Angle', 'S11_Re','S11_Im'}, 1);
    xlswrite(strcat(pathname, spreadsheet_filename), spreadsheet_content, 1, 'a2');
    disp('Done.');
else
    disp('No such frequency was found in the files.');
end

