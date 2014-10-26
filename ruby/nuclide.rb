class Nuclide
  C=299792458 #m/s
  U=931.494028 #MeV/C^2
  E=1.602176487e-19 #Coulombs
  Filename = 'mass.mas114'

	attr_accessor :info
	
  def initialize(name,a)
    
    file = File.new(Filename, 'r')
    @info=Hash.new
    line=Array.new
    counter = 0;
    while line=file.gets
      counter = counter  + 1
      next if counter < 40
      line.chomp!
      @info[:n_minus_z] = line[1..3].gsub!(/\s/, '').to_i
      @info[:neutron_number] = line[4..8].gsub!(/\s/, '').to_i
      @info[:proton_number] = line[9..13].gsub!(/\s/, '').to_i
      raise "N and Z don't match" if not @info[:n_minus_z] = @info[:neutron_number] - @info[:n_minus_z]
      @info[:atomic_mass] = line[14..19].gsub!(/\s/, '').to_i
      @info[:element_name] = line[20..22].gsub!(/\s/, '').to_s
      break if @info[:atomic_mass] == a and @info[:element_name] == name
      #include
    end
	file.close
	@info[:origin] = line[23..27].gsub!(/\s/, '').to_s
	@info[:mass_in_kev] = line[28..41].gsub!(/\s/, '').to_s
	@info[:mass_in_kev_unc] = line[42..52].gsub!(/\s/, '').to_s
	@info[:binding_per_u_in_kev] = line[53..63].gsub!(/\s/, '').to_s
	@info[:binding_per_u_in_kev_unc] = line[64..73].gsub!(/\s/, '').to_s
	@info[:beta_type] = line[74..75].gsub!(/\s/, '').to_s
	@info[:beta_in_key] = line[76..86].gsub!(/\s/, '').to_s
	@info[:beta_in_key_unc] = line[87..96].gsub!(/\s/, '').to_s
	@info[:atm_mass_in_microu] = line[97..112].gsub!(/\s/, '').to_s
	@info[:atm_mass_in_microu_unc] = line[113..123].gsub!(/\s/, '').to_s
  end

end
