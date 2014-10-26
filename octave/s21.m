% Script for extracting magnitude and phase 
% information from a MWO Plot
%


load new_first_s21_dry.txt;
% load second_s21_dry.txt;
% load first_s21_wet.txt;
% load second_s21_wet.txt;

freq = new_first_s21_dry (:,1);
% freq = second_s21_wet (:,1);

% -------- Phase Plot ---------

figure;
first_phase_dry = new_first_s21_dry (:,3);
% second_phase_dry = second_s21_dry (:,3);
% first_phase_wet = first_s21_wet (:,3);
% second_phase_wet = second_s21_wet (:,3);

first_phase_dry_unwrapped = unwrap (first_phase_dry);
% second_phase_dry_unwrapped = unwrap (second_phase_dry);
% first_phase_wet_unwrapped = unwrap (first_phase_wet);
% second_phase_wet_unwrapped = unwrap (second_phase_wet);

% plot (freq, first_phase_dry_unwrapped, freq, second_phase_dry_unwrapped, freq, first_phase_wet_unwrapped, freq, second_phase_wet_unwrapped);
% plot (freq, first_phase_dry_unwrapped, freq, first_phase_wet_unwrapped);
plot (freq, first_phase_dry_unwrapped);
% legend('1st dry', '2nd dry', '1st wet', '2nd wet');
legend('1st dry');
xlabel('Frequency [GHz]');
ylabel('Phase [Deg]');
title ('S21 Phase');
grid on;


% -------- Magnitude Plot ---------

figure;
first_magnitude_dry = new_first_s21_dry (:,2);
% second_magnitude_dry = second_s21_dry (:,2);
% first_magnitude_wet = first_s21_wet (:,2);
% second_magnitude_wet = second_s21_wet (:,2);

% plot (freq, first_magnitude_dry, freq, second_magnitude_dry, freq, first_magnitude_wet, freq, second_magnitude_wet);
% plot (freq, first_magnitude_dry, freq, first_magnitude_wet);
plot (freq, first_magnitude_dry);
axis ([2 3 -50 0]);
% legend('1st dry', '2nd dry', '1st wet', '2nd wet');
legend('1st dry');
xlabel('Frequency [GHz]');
ylabel('Magnitude [dB]');
title ('|S21|');
grid on;
