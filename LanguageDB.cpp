#include    "LanguageDB.h"

std::string Langs[] = {
    "ABAP", "ActionScript", "Ada", "ADSO/IDSM", "AMPLE", "Ant", "Apex Trigger", 
    "Arduino Sketch", "ASP", "ASP.Net", "Assembly", "AutoHotkey", "awk", "Bourne Again Shell", 
    "Bourne Shell", "C", "C Shell", "C#", "C++", "C/C++ Header", "CCS", "Clojure", 
    "ClojureScript", "CMake", "COBOL", "CoffeeScript", "ColdFusion", "ColdFusion CFScript", 
    "CSS", "CUDA", "Cython", "D/dtrace", "DAL", "Dart", "diff", "DITA", "DOS Batch", "DTD", 
    "ECPP", "Elixir", "ERB", "Erlang", "Expect", "F#", "Focus", "Fortran 77", "Fortran 90", 
    "Fortran 95", "Go", "Grails", "Groovy", "Haml", "Handlebars", "Harbour", "Haskell", 
    "HLSL", "HTML", "IDL", "IDL/Qt Project/Prolog", "InstallShield", "Java", "Javascript", 
    "JavaServer Faces", "JCL", "JSON", "JSP", "Kermit", "Korn Shell", "Kotlin", "LESS", "lex", 
    "Lisp", "Lisp/Julia", "Lisp/OpenCL", "LiveLink OScript", "Lua", "m4", "make", "MATLAB", 
    "Maven", "Modula3", "MSBuild script", "MUMPS", "Mustache", "MXML", "NAnt script", 
    "NASTRAN DMAP", "Objective C", "Objective C++", "OCaml", "Oracle Forms", "Oracle Reports", 
    "Pascal", "Pascal/Puppet", "Patran Command Language", "Perl", "Perl/Prolog", "PHP", 
    "PHP/Pascal", "Pig Latin", "PL/I", "PowerShell", "Prolog", "Protocol Buffers", "PureScript", 
    "Python", "QML", "R", "Racket", "Razor", "Rexx", "RobotFramework", "Ruby", "Ruby HTML", "Rust", 
    "SAS", "SASS", "Scala", "sed", "SKILL", "SKILL++", "Smarty", "Softbridge Basic", "SQL", 
    "SQL Data", "SQL Stored Procedure", "Standard ML", "Swift", "Tcl/Tk", "Teamcenter met", 
    "Teamcenter mth", "Titanium Style Sheet", "TypeScript", "Unity-Prefab", "Vala", "Vala Header", 
    "Velocity Template Language", "Verilog-SystemVerilog", "VHDL", "vim script", "Visual Basic", 
    "Visual Fox Pro", "Visualforce Component", "Visualforce Page", "Windows Message File", 
    "Windows Module Definition", "Windows Resource File", "WiX include", "WiX source", 
    "WiX string localization", "XAML", "xBase", "xBase Header", "XML", "XQuery", "XSD", "XSLT", 
    "yacc", "YAML"
    
};

std::string Langs_exts[][10] = {
    {"abap"},{"as"},{"ada, adb, ads, pad"},{"adso"},{"ample, dofile, startup"},{"build.xml"},
    {"trigger"},{"ino, pde"},{"asa, asp"},{"asax, ascx, asmx, aspx, config, master, sitemap, webinfo"},
    {"asm, s, S"},{"ahk"},{"awk"},{"bash"},{"sh"},{"c, ec, pgc"},{"csh, tcsh"},{"cs"},
    {"C, c++, cc, cpp, cxx, pcc"},{"h, H, hh, hpp"},{"ccs"},{"clj"},{"cljs"},{"cmake, CMakeLists.txt"},
    {"cbl, CBL, cob, COB"},{"coffee"},{"cfm"},{"cfc"},{"css"},{"cu"},{"pyx"},{"d"},{"da"},{"dart"},{"diff"},{"dita"},
    {"bat, BAT, btm, BTM, cmd, CMD"},{"dtd"},{"ecpp"},{"ex, exs"},{"ERB, erb"},{"erl, hrl"},{"exp"},{"fs, fsi"},
    {"fs, fsi"},{"f, F, f77, F77, for, FOR, FTN, ftn, pfo"},{"f90, F90"},{"f95, F95"},{"go"},{"gsp"},
    {"gant, gradle, groovy"},{"haml"},{"handlebars, hbs"},{"hb"},{"hs, lhs"},{"cg, cginc, shader"},{"htm, html"},
    {"idl"},{"pro"},{"ism"},{"java"},{"js"},{"jsf, xhtml"},{"jcl"},{"json"},{"jsp, jspf"},{"ksc"},{"ksh"},{"kt"},{"less"},{"l"},{"el, lisp, lsp, sc"},
    {"jl"},{"cl"},{"oscript"},{"lua"},{"ac, m4"},{"am, gnumakefile, Gnumakefile, makefile, Makefile"},{"m"},{"pom, pom.xml"},
    {"i3, ig, m3, mg"},{"csproj, vbproj, vcproj, wdproj, wixproj"},{"mps, m"},{"mustache"},{"mxml"},{"build"},{"dmap"},{"m"},{"mm"},{"ml, mli, mll, mly"},{"fmt"},
    {"rex"},{"dpr, p, pas"},{"pp"},{"pcl, ses"},{"perl, plh, plx, pm"},{"perl, plh, plx, pm"},
    {"php, php3, php4, php5"},{"inc"},{"pig"},{"pl1"},{"ps1"},{"P"},{"proto"},{"purs"},{"py"},{"qml"},
    {"R"},{"rkt, rktl, sch, scm, scrbl, ss"},{"cshtml"},{"rexx"},{"robot, tsv"},{"rake, rb"},{"rhtml"},{"rs"},{"sas"},
    {"sass, scss"},{"scala"},{"sed"},{"il"},{"ils"},{"smarty, tpl"},{"sbl, SBL"},{"psql, sql, SQL"},{"data.sql"},
    {"spc.sql, spoc.sql, sproc.sql, udf.sql"},{"fun, sig, sml"},{"swift"},{"itk, tcl, tk"},{"met"},
    {"mth"},{"tss"},{"ts"},{"mat, prefab"},{"vala"},{"vapi"},{"vm"},{"sv, svh, v"},{"VHD, vhd, vhdl, VHDL"},{"vim"},{"bas, cls, ctl, dsr, frm, VB, vb, VBA, vba, vbs, VBS"},{"sca, SCA"},
    {"component"},{"page"},{"mc"},{"def"},{"rc, rc2"},{"wxi"},{"wxs"},{"wxl"},{"xaml"},{"prg"},
    {"ch"},{"XML, xml"},{"xq, xquery"},{"xsd, XSD"},{"xsl, XSL, xslt, XSLT"},{"y"},{"yaml, yml"}
};