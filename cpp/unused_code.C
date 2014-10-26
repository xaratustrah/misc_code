//______________________________________________________________________________
// calculate the bead formula: calculates the field constant K = E_0^2 - 0.5 H_0^2
Double_t formula_metallic_needle(Double_t f_0, Double_t f){
     
     // used constants: none
     // generates: normalized electric field

     // The field in Maier+Slater is normalized to 1 and has units of m^-3.
     // we use the US definition where R = U^2/Pl

     Double_t a = 9.18 / 2 * 1e-3;	// major axis in meters
     Double_t beta = 9.18 / 0.76 * 1e-3; // slenderness in meters

     f_0 = f_0 * 1e6;
     f = f * 1e6;
    
     Double_t B = 6*TMath::Power(1-TMath::Power(beta, 2), 1.5)
	  /TMath::Log((1+TMath::Sqrt(1-TMath::Power(beta, 2)))/(1-TMath::Sqrt(1-TMath::Power(beta, 2))))-TMath::Sqrt(1-TMath::Power(beta, 2));

     Double_t e_norm_2 =
	  (TMath::Power(f_0,2)-TMath::Power(f,2))/
	  TMath::Power(f_0,2) /
	  (4*TMath::Pi()*TMath::Power(a,3))
	  *6*B; // results in |E^2| in units of m^-3.
    
     // we can convert this for under the integral by multiplication with constant:
    
     Double_t constant = 1/epsilon_0/TMath::Pi()/f_0; // In units of ohms*meter
     Double_t integrand = TMath::Sqrt(e_norm_2 * constant); // this gives us the normalized R/Q in units of sqrt(ohm)/m
    
     // this value will be returned for integration and squaring
     return integrand;
}


//______________________________________________________________________________
// calculates the normalized e field as in CST MWS
Double_t formula_metallic_needle_e_field_cst(Double_t f_0, Double_t f){

// in CST Microwave Studio the results of the field calculation is normalized
// such that the total stored energy is 1 joule

     Double_t a = 9.18 / 2 * 1e-3;	// major axis in meters
     Double_t beta = 9.18 / 0.76 * 1e-3; // slenderness in meters

     const Double_t U = 1;
 
    f_0 = f_0 * 1e6;		// in Hz
     f = f * 1e6;		// in Hz

     Double_t B = 6*TMath::Power(1-TMath::Power(beta, 2), 1.5)
	  /TMath::Log((1+TMath::Sqrt(1-TMath::Power(beta, 2)))/(1-TMath::Sqrt(1-TMath::Power(beta, 2))))-TMath::Sqrt(1-TMath::Power(beta, 2));

     Double_t e_norm = TMath::Sqrt(
	  6*U/4/TMath::Pi()/TMath::Power(a, 3)/epsilon_0/B
	  * (TMath::Power(f_0,2)-TMath::Power(f,2)) / TMath::Power(f_0,2)
	  );
     return e_norm;
}

