#ifdef _WIN32
	#ifdef COMPILE_DLL
		#define SG_DLL __declspec(dllexport)
	#else
		#define SG_DLL __declspec(dllimport)
	#endif // COMPILE_DLL
#endif