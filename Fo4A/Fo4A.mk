##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Fo4A
ConfigurationName      :=Debug
WorkspacePath          :=D:/CodeLiteProject/HungLD/HungLD-Fo4A
ProjectPath            :=D:/CodeLiteProject/HungLD/HungLD-Fo4A/Fo4A
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Francis Lai
Date                   :=08/07/2018
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :="C:/Program Files (x86)/CodeBlocks/MinGW/bin/g++.exe"
SharedObjectLinkerName :="C:/Program Files (x86)/CodeBlocks/MinGW/bin/g++.exe" -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Fo4A.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := $(shell wx-config --rcflags)
RcCompilerName         :="C:/Program Files (x86)/CodeBlocks/MinGW/bin/windres.exe"
LinkOptions            :=  -mwindows $(shell wx-config   --libs --unicode=yes)
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)D:\CodeLiteProject\HungLD\Fo4A\hdr $(IncludeSwitch)"D:\C++ library\chilkat-9.5.0-x86_64-vc12\include" 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := "C:/Program Files (x86)/CodeBlocks/MinGW/bin/ar.exe" rcu
CXX      := "C:/Program Files (x86)/CodeBlocks/MinGW/bin/g++.exe"
CC       := "C:/Program Files (x86)/CodeBlocks/MinGW/bin/gcc.exe"
CXXFLAGS :=  -g -O0 -Wall $(shell wx-config --cxxflags --unicode=yes  ) $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(shell wx-config --cxxflags --unicode=yes  ) $(Preprocessors)
ASFLAGS  := 
AS       := "C:/Program Files (x86)/CodeBlocks/MinGW/bin/as.exe"


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
WXWIN:=C:\wxWidgets-3.0.4
WXCFG:=gcc_lib\mswu
PATH:=$PATH;C:\wxWidgets-3.0.4\lib\gcc_lib
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/hdr_GameHandle.cpp$(ObjectSuffix) $(IntermediateDirectory)/hdr_AppManagement.cpp$(ObjectSuffix) $(IntermediateDirectory)/hdr_MainFrame.cpp$(ObjectSuffix) $(IntermediateDirectory)/hdr_thread.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteProject/HungLD/HungLD-Fo4A/Fo4A/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/hdr_GameHandle.cpp$(ObjectSuffix): hdr/GameHandle.cpp $(IntermediateDirectory)/hdr_GameHandle.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteProject/HungLD/HungLD-Fo4A/Fo4A/hdr/GameHandle.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/hdr_GameHandle.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/hdr_GameHandle.cpp$(DependSuffix): hdr/GameHandle.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/hdr_GameHandle.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/hdr_GameHandle.cpp$(DependSuffix) -MM hdr/GameHandle.cpp

$(IntermediateDirectory)/hdr_GameHandle.cpp$(PreprocessSuffix): hdr/GameHandle.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/hdr_GameHandle.cpp$(PreprocessSuffix) hdr/GameHandle.cpp

$(IntermediateDirectory)/hdr_AppManagement.cpp$(ObjectSuffix): hdr/AppManagement.cpp $(IntermediateDirectory)/hdr_AppManagement.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteProject/HungLD/HungLD-Fo4A/Fo4A/hdr/AppManagement.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/hdr_AppManagement.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/hdr_AppManagement.cpp$(DependSuffix): hdr/AppManagement.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/hdr_AppManagement.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/hdr_AppManagement.cpp$(DependSuffix) -MM hdr/AppManagement.cpp

$(IntermediateDirectory)/hdr_AppManagement.cpp$(PreprocessSuffix): hdr/AppManagement.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/hdr_AppManagement.cpp$(PreprocessSuffix) hdr/AppManagement.cpp

$(IntermediateDirectory)/hdr_MainFrame.cpp$(ObjectSuffix): hdr/MainFrame.cpp $(IntermediateDirectory)/hdr_MainFrame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteProject/HungLD/HungLD-Fo4A/Fo4A/hdr/MainFrame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/hdr_MainFrame.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/hdr_MainFrame.cpp$(DependSuffix): hdr/MainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/hdr_MainFrame.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/hdr_MainFrame.cpp$(DependSuffix) -MM hdr/MainFrame.cpp

$(IntermediateDirectory)/hdr_MainFrame.cpp$(PreprocessSuffix): hdr/MainFrame.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/hdr_MainFrame.cpp$(PreprocessSuffix) hdr/MainFrame.cpp

$(IntermediateDirectory)/hdr_thread.cpp$(ObjectSuffix): hdr/thread.cpp $(IntermediateDirectory)/hdr_thread.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteProject/HungLD/HungLD-Fo4A/Fo4A/hdr/thread.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/hdr_thread.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/hdr_thread.cpp$(DependSuffix): hdr/thread.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/hdr_thread.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/hdr_thread.cpp$(DependSuffix) -MM hdr/thread.cpp

$(IntermediateDirectory)/hdr_thread.cpp$(PreprocessSuffix): hdr/thread.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/hdr_thread.cpp$(PreprocessSuffix) hdr/thread.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


