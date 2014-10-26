public class FOModel {
	public FOModel() {

	}

	public static String makeString(String name, Complex z) {
		return name + " = " + new Double(z.getAbs()).toString()
				+ " * exp (j * "
				+ new Double(z.getArgAsDegrease() % 360).toString()
				+ " = " + new Double(z.getReal()).toString()
				+ " + j " + new Double(z.getImag()).toString() + " (Phase in Degrees)";
	}

}
