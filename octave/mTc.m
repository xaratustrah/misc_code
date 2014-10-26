% run in Octave

disp('How much electromagnetic power does 1 gramm of 99m-Tc radiate?')

% constants

NA = 6.0221413e+23 % [1/mol]
eV = 1.60217657e-19 % [J]

% given

molar_mass = 99 % [g/mol]
half_life = 6.0058 % [hours]
t12 = half_life * 3600 % [s]
gamma_energy_in_eV = 140e3 % [eV]
amount_in_gram = 1 % [g]

% calculate

amount_in_mol = amount_in_gram / molar_mass
no_of_atoms = NA * amount_in_mol
lambda = log(2) / t12 % [1/s]
activity_in_becquerel = lambda * no_of_atoms % [Bq]
power_in_watts = activity_in_becquerel * gamma_energy_in_eV * eV % [W]
