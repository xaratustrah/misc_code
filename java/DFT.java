import java.lang.Math;

public class DFT {

     public static void calculateDFT (int samplingFrequency, double [] sampledPoints) {

	  double realPart = 0, imagPart = 0, magnitude = 0, phase = 0;
          int currentAnalysisFrequency = 0; 
	  int numberOfDFTPoints = sampledPoints.length;
	  double two_PI_DevidedByNumberOfDFTPoints = (2* Math.PI) / numberOfDFTPoints;
	  int freqDomainUnit = samplingFrequency / numberOfDFTPoints;

         System.out.println("#This is the DFT result table prepared to be plotted by GNUPLot.");
         System.out.println("#Freq. \t\tReal \t\tImag \t\tMagnitudey \t\tPhase");
          
	  for (int m = 0; m < numberOfDFTPoints; m++){

	       currentAnalysisFrequency = m * freqDomainUnit;

	       for (int n = 0; n < numberOfDFTPoints; n++){
		    realPart = realPart + ( sampledPoints[n] * Math.cos( two_PI_DevidedByNumberOfDFTPoints * n * m ) );
		    //System.out.println("\n Current Real Part : " + realPart);
		    imagPart = imagPart - ( sampledPoints[n] * Math.sin( two_PI_DevidedByNumberOfDFTPoints * n * m ) );
		    //System.out.println(" Current Imag Part : " + imagPart);
                    // realPart = imagPart = 0;
	       }
              
               magnitude = Math.sqrt( Math.pow ( realPart, 2 ) + Math.pow ( imagPart, 2 ) );
               phase = Math.atan2(realPart, imagPart);
	       System.out.println (currentAnalysisFrequency + "\t\t" + realPart + " \t\t" + imagPart + "\t\t" + magnitude + "\t\t" + phase );
               
              
               realPart = imagPart = magnitude = phase =0;
	  }
	  return;
     }
     
     public static double [] originalSignal( int period, int samplingRate, boolean doPrint ){

	  double konst = (2 * Math.PI)/ period; 

	  double [] localArray = new double[samplingRate];
	  for ( int i = 0; i < localArray.length ; i++)
	  {
	       localArray [i] = Math.sin(konst * i);
	       if (doPrint) System.out.println(localArray[i]);
	  }
	  return localArray;
     }

//      public static double [] sampledSignal (double [] originalSignal)
// 	  {

// 	       double [] sampledSignal = new double [originalSignal.length/4];
// 	       int j = 0;
// 	      	  for ( int i = 0; i < sampledSignal.length ; i++)
// 	  {
// 	       sampledSignal [i] = originalSignal [j];
// 	       j = j + 4;
// 	       if (j > originalSignal.length) break;
// 	  }
// 	  return sampledSignal;
 
// 	  }

     public static void main ( String args [] ) {

	  double test [] = originalSignal(1, 4, true);
	  return;

     }
}
