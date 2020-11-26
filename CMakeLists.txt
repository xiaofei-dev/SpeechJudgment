cmake_minimum_required(VERSION 3.17)
project(Pitch)

file(GLOB SOURCES
        *.h						//*号对应具体的文件名
        *.cpp
        *.cc
        *.c
        )

set(CMAKE_CXX_STANDARD 14)

add_executable(
        Pitch
        main.cpp
        pitch/pitch.cpp
        pitch/pitch.h
        pitch/complex_defines.h
        pitch/support_functions.cpp
        pitch/support_functions.h
        pitch/resample.cpp
        pitch/resample.h

        webrtc/arch.h
        webrtc/checks.h
        webrtc/compile_assert_c.h
        webrtc/complex_fft_tables.h
        webrtc/cpu_features_wrapper.h
        webrtc/dot_product_with_scale.h
        webrtc/inline.h
        webrtc/real_fft.h
        webrtc/resample_by_2_internal.h
        webrtc/safe_compare.h
        webrtc/sanitizer.h
        webrtc/signal_processing_library.h
        webrtc/spl_inl.h
        webrtc/spl_sqrt_floor.h
        webrtc/typedefs.h
        webrtc/type_traits.h
        webrtc/vad_core.h
        webrtc/vad_filterbank.h
        webrtc/vad_gmm.h
        webrtc/vad_sp.h
        webrtc/webrtc_vad.h
        webrtc/checks.cc
        webrtc/complex_bit_reverse.c
        webrtc/complex_fft.c
        webrtc/cross_correlation.c
        webrtc/division_operations.c
        webrtc/dot_product_with_scale.cc
        webrtc/downsample_fast.c
        webrtc/energy.c
        webrtc/get_scaling_square.c
        webrtc/min_max_operations.c
        webrtc/resample_48khz.c
        webrtc/resample_by_2_internal.c
        webrtc/resample_fractional.c
        webrtc/spl_init.c
        webrtc/spl_inl.c
        webrtc/spl_sqrt.c
        webrtc/spl_sqrt_floor.c
        webrtc/vad_core.c
        webrtc/vad_filterbank.c
        webrtc/vad_gmm.c
        webrtc/vad_sp.c
        webrtc/vector_scaling_operations.c
        webrtc/webrtc_vad.c
)