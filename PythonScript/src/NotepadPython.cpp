
#include "stdafx.h"
#include "NotepadPython.h"
#include "Notepad_Plus_msgs.h"
#include "NotepadPlusWrapper.h"

using namespace boost::python;

void export_notepad()
{
	class_<NotepadPlusWrapper>("Editor", no_init)
		.def("new", &NotepadPlusWrapper::newDocument, "Create a new document")
		.def("save", &NotepadPlusWrapper::save, "Save the current file")
		.def("saveAs", &NotepadPlusWrapper::saveAs, "Save the current file as the specified filename")
		.def("saveAsCopy", &NotepadPlusWrapper::saveAsCopy, "Save the current file as the specified filename, but don't change the filename")
		.def("getCurrentView", &NotepadPlusWrapper::getCurrentView, "Get the currently active view (0 or 1)")
		.def("getCurrentLang", &NotepadPlusWrapper::getCurrentLangType, "Get the current language type (returns the LANGTYPE.xxx constants)")
		.def("setCurrentLang", &NotepadPlusWrapper::setCurrentLangType, "Set the current language type (use LANGTYPE.xxx constants)")
		.def("getFiles", &NotepadPlusWrapper::getFiles, "Gets a list of the open filenames, as a list of tuples (filename, bufferID, index, view)")
		.def("saveSession", &NotepadPlusWrapper::saveSession, "Saves a session file with the list of files (sessionFilename, filesList)")
		.def("saveCurrentSession", &NotepadPlusWrapper::saveCurrentSession, "Save the current session (filename)")
		.def("createScintilla", &NotepadPlusWrapper::createScintilla, "Create a new Scintilla handle. Returns a Buffer object")
		.def("destroyScintilla", &NotepadPlusWrapper::destroyScintilla, "Destroy a Scintilla handle created with createScintilla")
		.def("getCurrentDocIndex", &NotepadPlusWrapper::getCurrentDocIndex, "Gets the current active index for the given view (0 or 1)")
		.def("setStatusBar", &NotepadPlusWrapper::setStatusBar, "Sets the status bar text. Call with the sectionID, and the string to show")
		.def("getPluginMenuHandle", &NotepadPlusWrapper::getPluginMenuHandle, "Gets the handle for the Plugins menu.")
		.def("activateIndex", &NotepadPlusWrapper::activateIndex, "Activates the document with the given view and index (view, index)")
		.def("reloadFile", &NotepadPlusWrapper::reloadFile, "Reloads a filename.")
		.def("saveAllFiles", &NotepadPlusWrapper::saveAllFiles, "Saves all currently unsaved files")
		.def("getPluginConfigDir", &NotepadPlusWrapper::getPluginConfigDir, "Gets the plugin config directory")
		.def("menuCommand", &NotepadPlusWrapper::menuCommand, "Runs a Notepad++ menu command - just pass the commandID (from the nativeLang file)")
		.def("getVersion", &NotepadPlusWrapper::getVersion, "Gets the Notepad++ version as a tuple - e.g. 5.6.8 becomes (5,6,8)")
		.def("hideTabBar", &NotepadPlusWrapper::hideTabBar, "Hides the Tab bar")
		.def("showTabBar", &NotepadPlusWrapper::showTabBar, "Shows the Tab bar")
		.def("getCurrentBufferID", &NotepadPlusWrapper::getCurrentBufferID, "Gets the bufferID of the currently active buffer")
		.def("reloadBuffer", &NotepadPlusWrapper::reloadBuffer, "Reloads a buffer - just pass the buffer ID")
		.def("getLangType", &NotepadPlusWrapper::getLangType, "Gets the language type of the current buffer. Pass a buffer ID to get the type of the specified buffer.")
		.def("getLangType", &NotepadPlusWrapper::getBufferLangType, "Gets the language type of the current buffer. Pass a buffer ID to get the type of the specified buffer.")
		.def("setLangType", &NotepadPlusWrapper::setLangType, "Sets the language type of the current buffer. Pass a buffer ID as the second parameter to set the language for a specific buffer.")
		.def("setLangType", &NotepadPlusWrapper::setBufferLangType, "Sets the language type of the current buffer. Pass a buffer ID as the second parameter to set the language for a specific buffer.")
		.def("getEncoding", &NotepadPlusWrapper::getEncoding, "Gets the encoding of the current buffer.  Pass a buffer ID to get the encoding of a specific buffer.")
		.def("getEncoding", &NotepadPlusWrapper::getBufferEncoding, "Gets the encoding of the current buffer.  Pass a buffer ID to get the encoding of a specific buffer.")
		.def("getFormatType", &NotepadPlusWrapper::getFormatType, "Gets the format type (i.e. Windows, Unix or Mac) of the current buffer.  Pass a buffer ID to get the format type of a specific buffer.")
		.def("getFormatType", &NotepadPlusWrapper::getBufferFormatType, "Gets the format type (i.e. Windows, Unix or Mac) of the current buffer.  Pass a buffer ID to get the format type of a specific buffer.")
		.def("setFormatType", &NotepadPlusWrapper::setFormatType, "Sets the format type (i.e. Windows, Unix or Mac) of the current buffer - use the FORMATTYPE enum.  Pass a buffer ID as the second parameter to set the format type of a specific buffer.")
		.def("setFormatType", &NotepadPlusWrapper::setBufferFormatType, "Sets the format type (i.e. Windows, Unix or Mac) of the current buffer - use the FORMATTYPE enum.  Pass a buffer ID as the second parameter to set the format type of a specific buffer.")
		.def("callback", &NotepadPlusWrapper::callback, "Registers a callback function for a notification. Arguments are (function, [list of NOTIFICATION IDs])");



	enum_<LangType>("LANGTYPE")
			.value("TXT", L_TXT)
			.value("PHP", L_PHP)
			.value("C", L_C)
			.value("CPP", L_CPP)
			.value("CS", L_CS)
			.value("OBJC", L_OBJC)
			.value("JAVA", L_JAVA)
			.value("RC", L_RC)
			.value("HTML", L_HTML)
			.value("XML", L_XML)
			.value("MAKEFILE", L_MAKEFILE)
			.value("PASCAL", L_PASCAL)
			.value("BATCH", L_BATCH)
			.value("INI", L_INI)
			.value("NFO", L_NFO)
			.value("USER", L_USER)
			.value("ASP", L_ASP)
			.value("SQL", L_SQL)
			.value("VB", L_VB)
			.value("JS", L_JS)
			.value("CSS", L_CSS)
			.value("PERL", L_PERL)
			.value("PYTHON", L_PYTHON)
			.value("LUA", L_LUA)
			.value("TEX", L_TEX)
			.value("FORTRAN", L_FORTRAN)
			.value("BASH", L_BASH)
			.value("FLASH", L_FLASH)
			.value("NSIS", L_NSIS)
			.value("TCL", L_TCL)
			.value("LISP", L_LISP)
			.value("SCHEME", L_SCHEME)
			.value("ASM", L_ASM)
			.value("DIFF", L_DIFF)
			.value("PROPS", L_PROPS)
			.value("PS", L_PS)
			.value("RUBY", L_RUBY)
			.value("SMALLTALK", L_SMALLTALK)
			.value("VHDL", L_VHDL)
			.value("KIX", L_KIX)
			.value("AU3", L_AU3)
			.value("CAML", L_CAML)
			.value("ADA", L_ADA)
			.value("VERILOG", L_VERILOG)
			.value("MATLAB", L_MATLAB)
			.value("HASKELL", L_HASKELL)
			.value("INNO", L_INNO)
			.value("SEARCHRESULT", L_SEARCHRESULT)
			.value("CMAKE", L_CMAKE)
			.value("YAML", L_YAML);

	enum_<FormatType>("FORMATTYPE")
		.value("WIN", WIN_FORMAT)
		.value("MAC", MAC_FORMAT)
		.value("UNIX", UNIX_FORMAT);

	enum_<BufferEncoding>("BUFFERENCODING")
		.value("ENC8BIT", uni8Bit)
		.value("UTF8", uniUTF8)
		.value("UCS2BE", uni16BE)
		.value("UCS2LE", uni16LE)
		.value("COOKIE", uniCookie)
		.value("ANSI", uni7Bit)
		.value("UCS2BE_NOBOM", uni16BE_NoBOM)
		.value("UCS2LE_NOBOM", uni16LE_NoBOM);
	
	enum_<StatusBarSection>("STATUSBARSECTION")
		.value("DOCTYPE", STATUSBARSECTION_DOCTYPE)
		.value("DOCSIZE", STATUSBARSECTION_DOCSIZE)
		.value("CURPOS", STATUSBARSECTION_CURPOS)
		.value("EOFFORMAT", STATUSBARSECTION_EOFFORMAT)
		.value("UNICODETYPE", STATUSBARSECTION_UNICODETYPE)
		.value("TYPINGMODE", STATUSBARSECTION_TYPINGMODE);

	enum_<Notification>("NOTIFICATION")
		.value("READY", NPPNOTIF_READY)
		.value("TBMODIFICATION", NPPNOTIF_TBMODIFICATION)
		.value("FILEBEFORECLOSE", NPPNOTIF_FILEBEFORECLOSE)
		.value("FILEOPENED", NPPNOTIF_FILEOPENED)
		.value("FILECLOSED", NPPNOTIF_FILECLOSED)
		.value("FILEBEFOREOPEN", NPPNOTIF_FILEBEFOREOPEN)
		.value("FILEBEFORESAVE", NPPNOTIF_FILEBEFORESAVE)
		.value("FILESAVED", NPPNOTIF_FILESAVED)
		.value("SHUTDOWN", NPPNOTIF_SHUTDOWN)
		.value("BUFFERACTIVATED", NPPNOTIF_BUFFERACTIVATED)
		.value("LANGCHANGED", NPPNOTIF_LANGCHANGED)
		.value("WORDSTYLESUPDATED", NPPNOTIF_WORDSTYLESUPDATED)
		.value("SHORTCUTREMAPPED", NPPNOTIF_SHORTCUTREMAPPED)
		.value("FILEBEFORELOAD", NPPNOTIF_FILEBEFORELOAD)
		.value("FILELOADFAILED", NPPNOTIF_FILELOADFAILED)
		.value("READONLYCHANGED", NPPNOTIF_READONLYCHANGED);



}

