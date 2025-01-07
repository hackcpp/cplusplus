function(addBin name)
    add_executable(${name} ${name}.cpp)
endfunction()

function(addBins bins)
    foreach(bin ${bins})
        addBin(${bin})
    endforeach()
endfunction()

