import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(200) )

process.source = cms.Source("PoolSource",
                                # replace 'myfile.root' with the source file you want to use
                                fileNames = cms.untracked.vstring(
            '/store/mc/RunIISummer20UL18MiniAODv2/GluGluHToTauTau_M-125_TuneCP5_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/2520000/131E67AB-892F-5843-B20A-2222619607BF.root' 
                )
                            )

process.demo = cms.EDAnalyzer('AK4Analyzer',
    recoJetCollection = cms.InputTag('slimmedJets'),
    genJetCollection = cms.InputTag('slimmedGenJets')
                              )

process.p = cms.Path(process.demo)