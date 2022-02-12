cmake_minimum_required( VERSION 3.5 )
project( "DNA Profiler" VERSION 1.0 LANGUAGES CXX )

include_directories( include )

add_executable( dna_profiler
                src/Database.cpp
                src/DNAProfiler.cpp
                src/IOManager.cpp
                src/Sequence.cpp
              )
