#!/bin/bash
rosetta_path="/Users/mosavverulhassan/Documents/Rose/rosetta_mh"
cd $rosetta_path/source
./scons.py bootcamp_jd2 
bin/bootcamp_jd2.default.macosclangdebug -in:file:s src/apps/pilot/mhassan/PDB/1UBQ.pdb.gz -database ../database -ignore_unrecognized_res

