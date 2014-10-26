

//______________________________________________________________________________
// calculate the Slater formula
// Double_t formula_slater_field(Double_t f_0, Double_t f, Double_t major, Double_t minor){

//      f_0 = f_0 * 1e6;		// change to Hz
//      f = f * 1e6;

//      // reference energy in volumne in joules
 
//      // needle
//      Double_t a = major / 2 * 1e-3;	// major axis in meters
//      Double_t b = minor / 2 * 1e-3;			// minor axis in meters

//      //bead
//      //    Double_t a = b = 1.5e-3;

//      Double_t beta = b / a;	// slenderness

//      Double_t B = (Double_t) TMath::Power((1 - beta * beta), 0.3e1 / 0.2e1) / (TMath::Log((0.1e1 + TMath::Sqrt((Double_t) (1 - beta * beta))) / (0.1e1 - TMath::Sqrt((Double_t) (1 - beta * beta)))) / 0.2e1 - TMath::Sqrt((Double_t) (1 - beta * beta)));

// //     B = 0.75; too thick

//      cout << "B is: " << B << endl;

//      Double_t field_norm = TMath::Sqrt(
// 	  (TMath::Power(f_0,2)-TMath::Power(f,2)) /  TMath::Power(f_0,2)
// 	  * 6 / (4*TMath::Pi()*TMath::Power(a, 3)*epsilon_0 * B)
// 	  );

//      return field_norm;
// }


//______________________________________________________________________________
// calculate the bead formula: calculates the field constant K = E_0^2 - 0.5 H_0^2
Double_t formula_metallic_bead(Double_t f_0, Double_t f){
     
     // used constants: none
     // generates: normalized electric field

     // The field in Maier+Slater is normalized to 1 and has units of m^-3.
     // we use the US definition where R = U^2/Pl

     const Double_t r_bead = 1.5e-3; // radius of the bead in meters
//     const Double_t r_bead_err=1e-4;


     f_0 = f_0 * 1e6;
     f = f * 1e6;
    
     Double_t e_norm_2 =
	  (TMath::Power(f_0,2)-TMath::Power(f,2))/
	  TMath::Power(f_0,2) /
	  (4*TMath::Pi()*TMath::Power(r_bead,3)); // results in |E^2| in units of m^-3.
    
     // we can convert this for under the integral by multiplication with constant:
    
     Double_t constant = 1/epsilon_0/TMath::Pi()/f_0; // In units of ohms*meter
     Double_t integrand = TMath::Sqrt(e_norm_2 * constant); // this gives us the normalized R/Q in units of sqrt(ohm)/m
    
     // this value will be returned for integration and squaring
     return integrand;
}

//______________________________________________________________________________
// calculates the normalized e field as in CST MWS
Double_t formula_metallic_bead_e_field_cst(Double_t f_0, Double_t f){

// in CST Microwave Studio the results of the field calculation is normalized
// such that the total stored energy is 1 joule

     const Double_t r_bead = 1.5e-3; // radius of the bead in meters
     const Double_t U = 1;
     f_0 = f_0 * 1e6;
     f = f * 1e6;

     Double_t e_norm = TMath::Sqrt(
	  2*U/4/TMath::Pi()/TMath::Power(r_bead, 3)/epsilon_0
	  * (TMath::Power(f_0,2)-TMath::Power(f,2)) / TMath::Power(f_0,2)
	  );
     return e_norm;
}

