#if !defined CONVERTENCODING_INC_
	#define CONVERTENCODING_INC_

	#if !defined PACK_PLUGIN_VERSION
        #define PACK_PLUGIN_VERSION(%0,%1,%2) (((%0) << 16) | ((%1) << 8) | (%2))
    #endif

    #define CONVERTENCODING_VERSION PACK_PLUGIN_VERSION(2, 0, 0)
    #define CONVERTENCODING_INCLUDE_VERSION CONVERTENCODING_VERSION // backward compatibility

	#if !defined __cplusplus

        #define TIS620  "TIS-620"
        #define UTF8    "UTF-8"

		native ConvertEncoding(const input[], const from[], const to[], output[], size = sizeof output);

	#endif
#endif