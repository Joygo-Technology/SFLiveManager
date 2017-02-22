#ifndef __OSL_RWLOCK_H__
#define __OSL_RWLOCK_H__


#ifdef __cplusplus
extern "C"
{
#endif

#ifdef ANDROID 
#include  "osl_mutex.h"
#define osl_rwlock_create                   osl_mutex_create
#define osl_rwlock_destroy(rwlock )         osl_mutex_destroy(rwlock);
#define osl_rwlock_read_lock(rwlock )       osl_mutex_lock(rwlock, -1)
#define osl_rwlock_read_unlock(rwlock )     osl_mutex_unlock(rwlock)
#define osl_rwlock_write_lock(rwlock )      osl_mutex_lock(rwlock, -1)
#define osl_rwlock_write_unlock(rwlock )    osl_mutex_unlock(rwlock)
#else
/* 创建读写锁 */
void* osl_rwlock_create();

/* 销毁读写锁 */
void osl_rwlock_destroy( void* rwlock );

/* 读锁定 */
void osl_rwlock_read_lock( void* rwlock );

/* 读解锁 */
void osl_rwlock_read_unlock( void* rwlock );

/* 写锁定 */
void osl_rwlock_write_lock( void* rwlock );

/* 写解锁 */
void osl_rwlock_write_unlock( void* rwlock );
#endif

#ifdef __cplusplus
}
#endif

#endif
