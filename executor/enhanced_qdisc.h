typedef void (*qdisc_faill_func)(char* error, int error_num);

extern "C" __setup_qdisc(const char* arg_ifname, const qdisc_faill_func func);
extern "C" __reset_qdisc();

extern "C" long pseudo_addqdisc(volatile long parent, volatile long opts, volatile long size);
extern "C" long pseudo_addclass(volatile long port_qdisc, volatile long opts, volatile long size);

extern "C" long pseudo_changeqdisc(volatile long opts, volatile long size);
extern "C" long pseudo_changeclass(volatile long opts, volatile long size);

extern "C" long pseudo_delqdisc(volatile long opts, volatile long size);
extern "C" long pseudo_delclass(volatile long opts, volatile long size);

extern "C" long pseudo_sendprio(volatile long handle, volatile long count, volatile long size);

void reset_qdisc()
{
    __reset_qdisc();
}

extern "C" static void error(char* error, int error_num)
{
    failmsg("error -> ", "%s , %d", error, error_num);
}

void setup_qdisc()
{
    __setup_qdisc("lo", &error);
}

#if SYZ_EXECUTOR || __NR_syz_addqdisc_root

static long syz_addqdisc_root(volatile long opts, volatile long size)
{
    return pseudo_addqdisc(ROOT_ID, opts, size);
}
#endif

#if SYZ_EXECUTOR || __NR_syz_addqdisc

static long syz_addqdisc(volatile long parent, volatile long opts, volatile long size)
{
    return pseudo_addqdisc(parent, opts, size);
}
#endif

#if SYZ_EXECUTOR || __NR_syz_addclass

static long syz_addclass(volatile long port_qdisc, volatile long class_num, volatile long opts, volatile long size)
{
    return pseudo_addclass(port_qdisc, class_num, opts, size);
}
#endif


#if SYZ_EXECUTOR || __NR_syz_changeqdisc

static long syz_changeqdisc(volatile long opts, volatile long size)
{
    return pseudo_changeqdisc(opts, size);
}
#endif

#if SYZ_EXECUTOR || __NR_syz_changeclass

static long syz_changeclass(volatile long opts, volatile long size)
{
    return pseudo_changeclass(opts, size);
}
#endif


#if SYZ_EXECUTOR || __NR_syz_delqdisc

static long syz_delqdisc(volatile long handle)
{
    return pseudo_delqdisc(handle);
}
#endif

#if SYZ_EXECUTOR || __NR_syz_delclass

static long syz_delclass(volatile long handle)
{
    return pseudo_delclass(handle);
}
#endif


#if SYZ_EXECUTOR || __NR_syz_sendprio

static long syz_sendprio(volatile long handle, volatile long count, volatile long size)
{
    return pseudo_sendprio(handle, count, size);
}
#endif