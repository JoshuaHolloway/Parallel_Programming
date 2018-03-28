VTune Amplifier creates the tachyon project directory under the $HOME/intel/amplxe/projects

Application:
<sample_code_dir>/tachyon_find_hotspots
/home/josh/Desktop/Parallel_Vision_Research/Parallel_Studio/Amplifier_VTune/tachyon/tachyon_find_hotspots

Parameters:
<sample_code_dir>/dat/balls.dat
/home/josh/Desktop/Parallel_Vision_Research/Parallel_Studio/Amplifier_VTune/tachyon/dat/balls.dat

To enable profiling, please set /proc/sys/kernel/yama/ptrace_scope to 0:
$ sudo sh -c 'echo 0 >/proc/sys/kernel/perf_event_paranoid'
