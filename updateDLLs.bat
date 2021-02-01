xcopy /Y "Questionnaire Framework"\*.h exportedFramework\include
xcopy /Y x64\Debug\"Questionnaire Framework.lib" exportedFramework\lib
xcopy /Y x64\Debug\"Questionnaire Framework.dll" exportedFramework\afterBuildDependencies\debug
xcopy /Y x64\Release\"Questionnaire Framework.dll" exportedFramework\afterBuildDependencies\release
xcopy /Y x64\Debug\"WindowsHooking.dll" exportedFramework\afterBuildDependencies\debug
xcopy /Y x64\Release\"WindowsHooking.dll" exportedFramework\afterBuildDependencies\release

xcopy /Y x64\Debug\"Questionnaire Framework.dll" "Questionnaire Terminal"\x64\Debug
xcopy /Y x64\Debug\"Questionnaire Framework.dll" "QuestionnaireGUI"\debug
xcopy /Y x64\Debug\"WindowsHooking.dll" "Questionnaire Terminal"\x64\Debug
xcopy /Y x64\Debug\"WindowsHooking.dll" "QuestionnaireGUI"\debug
xcopy /Y x64\Debug\"Questionnaire Framework.dll" "QuestionnaireFrameworkTest"\x64\Debug
xcopy /Y x64\Debug\"WindowsHooking.dll" "QuestionnaireFrameworkTest"\x64\Debug

xcopy /Y x64\Release\"Questionnaire Framework.dll" "Questionnaire Terminal"\x64\Release
xcopy /Y x64\Release\"Questionnaire Framework.dll" "QuestionnaireGUI"\release
xcopy /Y x64\Release\"WindowsHooking.dll" "Questionnaire Terminal"\x64\Release
xcopy /Y x64\Release\"WindowsHooking.dll" "QuestionnaireGUI"\release
xcopy /Y x64\Release\"Questionnaire Framework.dll" "QuestionnaireFrameworkTest"\x64\Release
xcopy /Y x64\Release\"WindowsHooking.dll" "QuestionnaireFrameworkTest"\x64\Release

