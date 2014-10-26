//______________________________________________________________________________
// Create a 2D graph from the ntuple
TGraph2D * efield_graph3d(TTree * t){
    
    Double_t t_x, t_z, t_ellipsoid;
    Int_t nentries, i, nbytes;
    char timestamp[15];
    
    t->SetBranchAddress("x", &t_x);
    t->SetBranchAddress("z", &t_z);
    t->SetBranchAddress("ellipsoid", &t_ellipsoid);
    t->SetBranchAddress("begin", &timestamp);
    t->GetEntry(0);
    
    TGraph2D * gr = new TGraph2D();
    
    nentries=(Int_t)t->GetEntries();
    
    for (i = 0;i<nentries;i++) {
        nbytes = t->GetEntry(i);
        gr->SetPoint(gr->GetN(),t_x, t_z, t_ellipsoid);
    }
    
    gr->SetTitle(Form("Measurement %s;X-offset [cm];Z-offset [cm];|E_{0}|(QP_{L})^{-1/2} [#Omega/m]", timestamp));
    gr->SetMarkerStyle(kOpenCircle);
    gr->SetMarkerColor(kBlue);
    gr->SetLineColor(kBlue);
    gr->SetMarkerStyle(7);
    
    gr->GetXaxis()->SetTitleOffset(1.6);
    gr->GetXaxis()->CenterTitle(true);
    gr->GetXaxis()->SetTitleSize(0.03);
    gr->GetXaxis()->SetLabelSize(0.03);
    
    gr->GetYaxis()->SetTitleOffset(1.6);
    gr->GetYaxis()->CenterTitle(true);
    gr->GetYaxis()->SetTitleSize(0.03);
    gr->GetYaxis()->SetLabelSize(0.03);
    
    gr->GetZaxis()->SetTitleOffset(1.6);
    gr->GetZaxis()->CenterTitle(true);
    gr->GetZaxis()->SetTitleSize(0.03);
    gr->GetZaxis()->SetLabelSize(0.03);
    
    return gr;
}


