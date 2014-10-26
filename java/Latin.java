import java.awt.*;
import java.applet.*;
public class Latin extends Applet
{
public void paint (Graphics g)
{
	String [][] SubsSingEndung= new String [3][5];
	SubsSingEndung[1][1]="us";	//Nominativ maskulin
	SubsSingEndung[1][2]="i";	//Genetiv maskulin
	SubsSingEndung[1][3]="o";	//Dativ maskulin
	SubsSingEndung[1][4]="um";	//Akkusativ maskulin
	SubsSingEndung[1][5]="õ";	//Ablativ maskulin
	SubsSingEndung[2][1]="a";	//Nominativ Feminin
	SubsSingEndung[2][2]="æ";	//Genetiv Feminin
	SubsSingEndung[2][3]="æ";	//Dativ Feminin
	SubsSingEndung[2][4]="am";	//Akkusativ Feminin
	SubsSingEndung[2][5]="â";	//Ablativ Feminin
	SubsSingEndung[3][1]="um";	//Nominativ neutrum
	SubsSingEndung[3][2]="o";	//Genetiv neutrum
	SubsSingEndung[3][3]="um";	//Dativ neutrum
	SubsSingEndung[3][4]="ô";	//Akkusativ neutrum
	SubsSingEndung[3][5]="i";	//Ablativ neutrum

	String [][] SubsPlEndung= new String [3][5];
	SubsPlEndung[1][1]="i";		//Nominativ maskulin
	SubsPlEndung[1][2]="orum";	//Genetiv maskulin
	SubsPlEndung[1][3]="îs";	//Dativ maskulin
	SubsPlEndung[1][4]="ôs";	//Akkusativ maskulin
	SubsPlEndung[1][5]="îs";	//Ablativ maskulin
	SubsPlEndung[2][1]="æ";		//Nominativ Feminin
	SubsPlEndung[2][2]="arum";	//Genetiv Feminin
	SubsPlEndung[2][3]="îs";	//Dativ Feminin
	SubsPlEndung[2][4]="âs";	//Akkusativ Feminin
	SubsPlEndung[2][5]="îs";	//Ablativ Feminin
	SubsPlEndung[3][1]="a";		//Nominativ neutrum
	SubsPlEndung[3][2]="orum";	//Genetiv neutrum
	SubsPlEndung[3][3]="îs";	//Dativ neutrum
	SubsPlEndung[3][4]="a";		//Akkusativ neutrum
	SubsPlEndung[3][5]="îs";	//Ablativ neutrum

}
}
