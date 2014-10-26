import java.io.InputStreamReader;
import java.io.LineNumberReader;
import java.io.FileReader;
import java.util.Date;

class dynhtml {

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
	       readFromInput(localFile);
	       return;

	  }

	  // check if this argument is the --help swich
	  if(args[0].equals("--help")){

	       System.out.println("\n NAME: \n\n jcat - concatenate and print files \n\n SYNOPSIS: \n\n java jcat [file ... ]");
	       System.out.println(" The jcat utility reads files sequentially, writing them to the standard\n output.  The file operands are processed in command-line order.  If file\nis a single dash (`-') or absent, jcat reads from the standard input. ");
	       System.out.println(" The --help switch brings this help screen. \n");
	       return;
	  }

	  // if not, check if it is a filename.
	  else{
	       try{	
		    localFile = new LineNumberReader(new FileReader (args[0]));	   
		    readFromInput(localFile);
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

     private static void readFromInput(LineNumberReader local){
	  String line;
	  Date localDate = new Date();
	  try{
	       while((line =local.readLine()) != null){
		    if(local.getLineNumber()==1){
			System.out.println("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">\n<HTML>\n<HEAD>\n<TITLE>");
			System.out.println(line);
			System.out.println("</TITLE>\n<BODY>");
		    }
		    else if(local.getLineNumber()==2){
			 System.out.println("<P><FONT color=#3366ff><STRONG>");
			 System.out.println(line);
			 System.out.println("</STRONG></font></P>");
		    }
		    else {
			 System.out.println("<P>");
			 System.out.println(line);
			 System.out.println("</P>");
		    }
	       }
	       System.out.println("<HR><P><EM>Last Updated: "+ localDate.toString()+"</EM></P></BODY></HTML>");
	       
	  }
	  catch(java.io.IOException e2){
	       System.out.println("An error occured while trying to read the contents of the file. Now exiting... \n");
	       return;
	  }
	  finally{			      
	       try{
		    local.close();
	       }
	       catch(java.io.IOException e3){
		    System.out.println("Error closeing the file..... Exiting anyway." );
	       }				   
	       return;
	  }      
     }
}


      
