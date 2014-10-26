public class Kontroll12{
	public static void main(String args[]){
		String s = "Alle meine Entchen";
		int e=0;
		for (int i=0;i<s.length(); i++){
			if (s.charAt(i)=='E' || s.charAt(i)=='e') e++;
		}
		System.out.println(e);
	}
}