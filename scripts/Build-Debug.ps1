$OutDirs = [PSCustomObject]@{
    Bin = "build\debug\bin"
    Obj = "build\debug\obj"
    Lib = "build\debug\lib"
}

$OutFiles = [PSCustomObject]@{
    Obj = $OutDirs.Obj + "\SLD.Math.obj"
    Pdb = $OutDirs.Bin + "\SLD.Math.pdb" 
    Lib = $OutDirs.Lib + "\SLD.Math.lib"
    Dll = $OutDirs.Bin + "\SLD.Math.dll"
}

$CompileArgs = [PSCustomObject]@{
    Compiler = "cl.exe"
    In       = "src/sld-math.cpp"
    Out      = "/Fo:" + $OutFiles.Obj
    Include  = @(
        "/Isrc"
        "/Iinclude"
        "/ISLD.Core/include"
    ) -join " "
    Flags = @(
        "/nologo"             # startup banner disabled
        "/c"                  # compile without linking
        "/MD"                 # link against multithreaded runtime library (MSVCRT.dll)
        "/Z7"                 # generate debug info
        "/EHs-"               # disable exception handling
        "/std:c++17"          # c++17 standard mode
        "/Od"                 # disable optimizations
        "/D_HAS_EXCEPTIONS=0" # disable exceptions for STL and CRT
    ) -join " "    
}


$Expressions = [PSCustomObject]@{
    Compile = @(
        $CompileArgs.Compiler
        $CompileArgs.In
        $CompileArgs.Out
        $CompileArgs.Include
        $CompileArgs.Flags
    ) -join " "
}

Invoke-Expression $Expressions.Compile