{
  const char * trafo_filename = "Espec0336_short.txt";
ofstream outfile;
outfile.open ("results.txt");

  const Int_t time_unit = 1000; // miliseconds
  const Int_t number_of_bins = 1000; // seconds

  TH1D *trafo_plot = new TH1D(trafo_filename, trafo_filename, number_of_bins, 0, number_of_bins*time_unit); // make a histogram 
  ifstream infile;
  infile.open (trafo_filename, ifstream::in);
  Double_t time, s_clock, s_trafo, MA=0, new_value=0;
  Int_t bin_counter = 1; // bin number in root starts with 1 and ends with number of bins
  Int_t average_counter = 1, file_line_counter=0;
  while (1)
    {
      // check if there are stil lines in the file
      if (!infile.good()) {cout << "File ended at line number "<< file_line_counter << endl; break;} else {file_line_counter ++;}

      // read from the file
      infile >> time >> s_clock >> s_trafo;

      // time is in 100 us units, convert it to miliseconds.
      time = time / 10;
      // calculate the current
      new_value = s_trafo/s_clock*0.5;

      if (time < bin_counter * time_unit)
	{
	  // make average except if it is the first value
	  if (average_counter == 1) MA = new_value;
	  MA = (new_value + MA)/2;
	  average_counter ++;	  
	}

      else
	// one unit of time has reached, reset counters and put the point in the histogram
	{
	  //if (std::numeric_limits<double>::infinity() == MA) { /* blah */}
//	  if (fabs(MA) == std::numeric_limits::infinity()) {cout << "bad number" << endl;break;}
	  trafo_plot->SetBinContent(bin_counter, MA);
	  outfile << bin_counter << "\t"<< MA << endl;
	  bin_counter ++;
	  MA = new_value;
	  average_counter = 2;
	}
    }
  infile.close();
  outfile.close();

  TCanvas *c1 = new  TCanvas(" "," ",800,600);
  c1->ToggleEditor();
  c1->SetCrosshair();
  c1->ToggleEventStatus();
  c1->ToggleToolBar();

  trafo_plot->SetFillColor(kRed);
  trafo_plot->SetXTitle("Time[s]");
  trafo_plot->SetYTitle("Current [mA]");
  trafo_plot->Draw();
}
