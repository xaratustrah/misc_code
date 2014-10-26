// xaratustra 

import java.io.InputStreamReader;
import java.io.LineNumberReader;
import java.io.FileReader;

class jcat {

     public static void main( String[ ] args ) {
	  LineNumberReader localFile;

	  //check for too many parameters
	  if(args.length > 1){
	       System.out.println("Too many parameters. (\"jcat --help\" for help)");
	       return;
	  }
	  // case only one argument is given:
	  // check if it is "-" or empty.
	  if(args.length == 0 || args[0].equals("-") ){

	       localFile= new LineNumberReader(new InputStreamReader(System.in));
	       if(readFromInput(localFile) == 1)return;
	       return;

	  }

	  // check if this argument is the --help swich
	  if(args[0].equals("--help")){

	       System.out.println("\n NAME: \n\n jcat - concatenate and print files \n\n SYNOPSIS: \n\n [JAVA-HOME/bin/]java jcat [file ... ]\n Where JAVA-HOME should be replaced by the path of the JVM on your system.\n");
	       System.out.println(" The jcat utility reads files sequentially, writing them to the standard\n output.  The file operands are processed in command-line order.  If file\n is a single dash (`-') or absent, jcat reads from the standard input. ");
	       System.out.println(" The --help switch brings this help screen. \n");
	       return;
	  }

	  // if not, check if it is a filename.
	  else{
	       try{	
		    localFile = new LineNumberReader(new FileReader (args[0]));	   
		    if (readFromInput(localFile) == 1)return;
		    return;
	       }
	       catch (java.io.FileNotFoundException e1){
		    System.out.println("File not found! \n");
		    return;
	       }
	  }
     }

/**
 * This Method reads the input stream line by line and writes it to the standard output
 * and then closes the inputstream.
 */ 

     private static int readFromInput(LineNumberReader local){
	  String line;
	  try{
	       while((line =local.readLine()) != null){
		    System.out.println(line);
	       }
	  }
	  catch(java.io.IOException e2){
	       System.out.println("An error occurred while trying to read the contents of the file. Now exiting... \n");
	       return -1;
	  }
	  finally{			      
	       try{
		    local.close();
	       }
	       catch(java.io.IOException e3){
		    System.out.println("Error closing the file. Exiting anyway..." );
		    return -1;
	       }				   
	       return 0;
	  }      
     }
}


      
