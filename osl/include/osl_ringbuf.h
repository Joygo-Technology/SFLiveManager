#ifndef __OSL_RINGBUF_H__
#define __OSL_RINGBUF_H__


#ifdef __cplusplus
extern "C"
{
#endif

typedef struct _osl_ringbuf_t {
	volatile int head;
	volatile int tail;
	volatile int bufsize;
	volatile int full;
	unsigned char *buf;
} osl_ringbuf_t;


int osl_ringbuf_init(osl_ringbuf_t *ring_buf, int bufsize);

int osl_ringbuf_get_freesize(osl_ringbuf_t *ring_buf);

int osl_ringbuf_get_datasize(osl_ringbuf_t *ring_buf);

int osl_ringbuf_get_buffer_rate(osl_ringbuf_t *ring_buf);

int osl_ringbuf_write(osl_ringbuf_t *ring_buf, unsigned char *buf, int size);

int osl_ringbuf_write_aquire(osl_ringbuf_t *ring_buf, unsigned char**buf, int size);

int osl_ringbuf_write_confirm(osl_ringbuf_t *ring_buf, int size);

int osl_ringbuf_skip(osl_ringbuf_t *ring_buf, int size);

int osl_ringbuf_read(osl_ringbuf_t *ring_buf, unsigned char *buf, int size);

int osl_ringbuf_read_aquire(osl_ringbuf_t *ring_buf, unsigned char**buf, int size);

int osl_ringbuf_read_confirm(osl_ringbuf_t *ring_buf, int size);

int osl_ringbuf_reset(osl_ringbuf_t *ring_buf);

int osl_ringbuf_exit(osl_ringbuf_t *ring_buf);

#ifdef __cplusplus
}
#endif


#endif /* __OSL_RINGBUF_H__ */
