/**************************************** prototypes for jnicalls_*.c *.cpp */
#ifdef __cplusplus
extern "C" {
#endif
JNIEXPORT int JNICALL Java_link_infra_sslsockspro_service_StunnelService_beginStunnel(JNIEnv *env, jobject obj, jstring jstr);

JNIEXPORT void JNICALL Java_link_infra_sslsockspro_service_StunnelService_reloadStunnel(JNIEnv *env, jobject obj, jstring jstr);

JNIEXPORT void JNICALL Java_link_infra_sslsockspro_service_StunnelService_endStunnel(JNIEnv *env, jobject obj, jstring jstr);
/*
 * end extern
 */
#ifdef __cplusplus
}
#endif
