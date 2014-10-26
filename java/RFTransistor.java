public class RFTransistor extends Transistor {

	private Complex s11;

	private Complex s12;

	private Complex s21;

	private Complex s22;

	public RFTransistor() {
		this.s11 = null;
		this.s12 = null;
		this.s21 = null;
		this.s22 = null;
	}

	public RFTransistor(Complex s11, Complex s12, Complex s21, Complex s22) {
		this.s11 = s11;
		this.s12 = s12;
		this.s21 = s21;
		this.s22 = s22;
	}

	public void setS11(Complex z) {
		this.s11 = z;
	}

	public void setS12(Complex z) {
		this.s12 = z;
	}

	public void setS21(Complex z) {
		this.s21 = z;
	}

	public void setS22(Complex z) {
		this.s22 = z;
	}

	public Complex getS11() {
		return this.s11;
	}

	public Complex getS12() {
		return this.s12;
	}

	public Complex getS21() {
		return this.s21;
	}

	public Complex getS22() {
		return this.s22;
	}

	public boolean isUnilateral() {
		if (this.s12.getAbs() == 0 && this.s12.getArgAsDegrease() == 0) {
			return true;
		} else {
			return false;
		}
	}

	public boolean isUnconditionallyStable() {
		if (this.getK() > 1 & this.getDelta().getAbs() < 1) {
			return true;
		} else {
			return false;
		}
	}

	public Complex getDelta() {
		return Complex.sub(Complex.mul(this.s11, this.s22), Complex.mul(
				this.s12, this.s21));
	}

	public double getB1() {
		return 1 + Math.pow(this.s11.getAbs(), 2.0)
				- Math.pow(this.s22.getAbs(), 2.0)
				- Math.pow(this.getDelta().getAbs(), 2.0);
	}

	public double getB2() {
		return 1 + Math.pow(this.s22.getAbs(), 2.0)
				- Math.pow(this.s11.getAbs(), 2.0)
				- Math.pow(this.getDelta().getAbs(), 2.0);

	}

	public Complex getC1() {
		return Complex.sub(this.s11, Complex.mul(this.getDelta(), this.s22
				.conj()));

	}

	public Complex getC2() {
		return Complex.sub(this.s22, Complex.mul(this.getDelta(), this.s11
				.conj()));

	}

	public double getK() {
		return (1 - Math.pow(this.s11.getAbs(), 2.0)
				- Math.pow(this.s22.getAbs(), 2.0) + Math.pow(this.getDelta()
				.getAbs(), 2.0))
				/ (2 * Complex.mul(this.s12, this.s21).getAbs());
	}

	public Complex getGammaMS() {
		Complex GammaMS, GammaMS_den;
		double GammaMS_nom;

		if (this.getB1() < 0) {
			GammaMS_nom = this.getB1()
					+ Math.sqrt(Math.pow(this.getB1(), 2.0) - 4
							* Math.pow(this.getC1().getAbs(), 2.0));
		} else {
			GammaMS_nom = this.getB1()
					- Math.sqrt(Math.pow(this.getB1(), 2.0) - 4
							* Math.pow(this.getC1().getAbs(), 2.0));
		}
		GammaMS_den = Complex.mul(new Complex(2, 0), Complex.pow(this.getC1(),
				2));
		GammaMS = Complex.mul(Complex.div(new Complex(GammaMS_nom, 0),
				GammaMS_den), this.getC1().conj());
		return GammaMS;
	}

	public Complex getGammaML() {
		Complex GammaML, GammaML_den;
		double GammaML_nom;

		if (this.getB2() < 0) {
			GammaML_nom = this.getB2()
					+ Math.sqrt(Math.pow(this.getB2(), 2.0) - 4
							* Math.pow(this.getC2().getAbs(), 2.0));
		} else {
			GammaML_nom = this.getB2()
					- Math.sqrt(Math.pow(this.getB2(), 2.0) - 4
							* Math.pow(this.getC2().getAbs(), 2.0));
		}
		GammaML_den = Complex.mul(new Complex(2, 0), Complex.pow(this.getC2(),
				2));
		GammaML = Complex.mul(Complex.div(new Complex(GammaML_nom, 0),
				GammaML_den), this.getC2().conj());

		return GammaML;
	}

	public double getGTMax() {
		double GTMax;
		if (this.getB1() < 0) {
			GTMax = (this.s21.getAbs() / this.s12.getAbs())
					* (this.getK() + Math.sqrt(Math.pow(this.getK(), 2.0) - 1));
		} else {
			GTMax = (this.s21.getAbs() / this.s12.getAbs())
					* (this.getK() - Math.sqrt(Math.pow(this.getK(), 2.0) - 1));
		}
		return GTMax;
	}

	public double getGTMaxDB() {
		return 10 * Math.log10(this.getGTMax());
	}

	public double getMSG() {
		return this.s21.getAbs() / this.s12.getAbs();
	}

	public double getMAG() {
		// TODO
		return 0;
	}

	public Complex getCS() {
		Complex num;
		double denum;
		num = Complex.sub(Complex.mul(this.getS22(), this.getDelta().conj()),
				this.getS11().conj());
		denum = Math.pow(this.getDelta().getAbs(), 2.0)
				- Math.pow(this.getS22().getAbs(), 2.0);
		return Complex.div(num, new Complex(denum, 0, false));
	}

	public double getRS() {
		Complex num;
		double denum;
		num = Complex.mul(this.getS12(), this.getS21());
		denum = Math.pow(this.getDelta().getAbs(), 2.0)
				- Math.pow(this.getS22().getAbs(), 2.0);
		return Complex.div(num, new Complex(denum, 0, false)).getAbs();
	}
}
