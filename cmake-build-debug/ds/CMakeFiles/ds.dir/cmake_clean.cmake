file(REMOVE_RECURSE
  "libds.pdb"
  "libds.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/ds.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
