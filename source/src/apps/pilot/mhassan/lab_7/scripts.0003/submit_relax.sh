lab_path="~/Documents/Rose/rosetta_mh/source/src/apps/pilot/mhassan/lab_7"
bin_path="~/Documents/Rose/rosetta_mh/source/bin"
for i in `seq 1 3`
do
    for j in `seq 1 3`
    do
        echo "---Working on dir_$i_$j---" in pwd
        cd $lab_path/outputs.0002/dir_$i_$j/ && $bin_path/relax.default.macosclangrelease $lab_7/inputs.0001/relax_inputs.flags
    done
done
