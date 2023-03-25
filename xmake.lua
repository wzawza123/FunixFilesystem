target("funix")
    set_kind("binary")
    -- add include directories in every subdirectory of include
    add_includedirs("include/dev")
    add_includedirs("include/kernel")
    add_files("src/dev/*.cpp")
    -- add_files("src/fs/*.cpp")
    add_files("src/kernel/*.cpp")
