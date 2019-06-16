#!/bin/bash
g++ `root-config --cflags` -o HGCALAnalyzer test.cc histHgcal.cc inputHgcal.cc anaHgcal.cc  `root-config --glibs`
./HGCALAnalyzer pdgID211_beamMomentum100_listFTFP_BERT_EMM_v1 1 0
./HGCALAnalyzer pdgID211_beamMomentum120_listFTFP_BERT_EMM_v1 1 0
./HGCALAnalyzer pdgID211_beamMomentum200_listFTFP_BERT_EMM_v1 1 0
./HGCALAnalyzer pdgID211_beamMomentum20_listFTFP_BERT_EMM_v1 1 0
./HGCALAnalyzer pdgID211_beamMomentum250_listFTFP_BERT_EMM_v1 1 0
./HGCALAnalyzer pdgID211_beamMomentum300_listFTFP_BERT_EMM_v1 1 0
./HGCALAnalyzer pdgID211_beamMomentum50_listFTFP_BERT_EMM_v1 1 0
./HGCALAnalyzer pdgID211_beamMomentum80_listFTFP_BERT_EMM_v1 1 0
./HGCALAnalyzer pdgID2211_beamMomentum100_listFTFP_BERT_EMM_v1 1 0
./HGCALAnalyzer pdgID2211_beamMomentum120_listFTFP_BERT_EMM_v1 1 0
./HGCALAnalyzer pdgID2211_beamMomentum200_listFTFP_BERT_EMM_v1 1 0
./HGCALAnalyzer pdgID2211_beamMomentum20_listFTFP_BERT_EMM_v1 1 0
./HGCALAnalyzer pdgID2211_beamMomentum250_listFTFP_BERT_EMM_v1 1 0
./HGCALAnalyzer pdgID2211_beamMomentum300_listFTFP_BERT_EMM_v1 1 0
./HGCALAnalyzer pdgID2211_beamMomentum50_listFTFP_BERT_EMM_v1 1 0
./HGCALAnalyzer pdgID2211_beamMomentum80_listFTFP_BERT_EMM_v1 1 0
