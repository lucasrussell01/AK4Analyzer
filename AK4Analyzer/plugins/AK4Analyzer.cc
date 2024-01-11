// -*- C++ -*-
//
// Package:    MLAnalyzer/AK4Analyzer
// Class:      AK4Analyzer
//
// Original Author:  Lucas Russell
//         Created:  Wed, 10 Jan 2024 14:16:31 GMT
//


// system include files
#include <memory>
#include <iostream>
#include <vector>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"


#include "DataFormats/CLHEP/interface/AlgebraicObjects.h"


#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/PatCandidates/interface/Jet.h"


#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "TH1.h"


//
// class declaration
//


class AK4Analyzer : public edm::one::EDAnalyzer<edm::one::SharedResources> {
public:
  explicit AK4Analyzer(const edm::ParameterSet&);
  ~AK4Analyzer() override;

  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

private:
  void beginJob() override;
  void analyze(const edm::Event&, const edm::EventSetup&) override;
  void endJob() override;

  // ----------member data ---------------------------
  edm::EDGetTokenT<std::vector<pat::Jet>> recoJetsToken_;
  edm::EDGetTokenT<std::vector<reco::GenJet>> genJetsToken_;


};

// constructor
AK4Analyzer::AK4Analyzer(const edm::ParameterSet& iConfig)
{
  recoJetsToken_ = consumes<std::vector<pat::Jet>>(iConfig.getParameter<edm::InputTag>("recoJetCollection"));
  genJetsToken_ = consumes<std::vector<reco::GenJet>>(iConfig.getParameter<edm::InputTag>("genJetCollection"));

}
    
// destructor
AK4Analyzer::~AK4Analyzer() {

}
// member functions

// ------------ method called for each event  ------------
void AK4Analyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {

  using namespace edm;

  std::cout << "Test" << std::endl;

  // for (const auto& track : iEvent.get(tracksToken_)) {
  //   // do something with track parameters, e.g, plot the charge.
  //   // int charge = track.charge();
  // }

// #ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
//   // if the SetupData is always needed
//   auto setup = iSetup.getData(setupToken_);
//   // if need the ESHandle to check if the SetupData was there or not
//   auto pSetup = iSetup.getHandle(setupToken_);
// #endif
}

// ------------ method called once each job just before starting event loop  ------------
void AK4Analyzer::beginJob() {
  // please remove this method if not needed
}

// ------------ method called once each job just after ending the event loop  ------------
void AK4Analyzer::endJob() {
  // please remove this method if not needed
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void AK4Analyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);

  //Specify that only 'tracks' is allowed
  //To use, remove the default given above and uncomment below
  //ParameterSetDescription desc;
  //desc.addUntracked<edm::InputTag>("tracks","ctfWithMaterialTracks");
  //descriptions.addWithDefaultLabel(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(AK4Analyzer);
