enum qdisc_type {
    Q_UNDEF,
    Q_CAKE,
    Q_CBS,
    Q_CHOKE,
    Q_CODEL,
    Q_ETF,
    Q_ETS,
    Q_BFIFO,
    Q_PFIFO,
    Q_PFIFO_HEAD_DROP,
    Q_FQ,
    Q_FQ_CODEL,
    Q_FQ_PIPE,
    Q_GRED,
    Q_HHF,
    Q_NETEM,
    Q_PIE,
    Q_PRIO,
    Q_PLUG,
    Q_RED,
    Q_SFB,
    Q_SFQ,
    Q_SKBPRIO,
    Q_TBF,
    Q_DUALAPI,
    Q_DRR,
    Q_BLACKHOLE,
    Q_PFIFO_FAST,
    Q_QFQ,
    Q_HTB,
    Q_HFSC,
    Q_MAX,
    Q_ERROR
};

typedef void (*qdisc_faill_func)(char* error, int error_num);

extern "C" void __setup_qdisc(const char* arg_ifname, const qdisc_faill_func func);
extern "C" void __reset_qdisc();

extern "C" long pseudo_addqdisc(volatile long parent, volatile long opts, volatile long size);
extern "C" long pseudo_addclass(volatile long type, volatile long portid, volatile long class_num, volatile long opt, volatile long opt_size);

extern "C" long pseudo_changeqdisc(volatile long opts, volatile long size);
extern "C" long pseudo_changeclass(volatile long opts, volatile long size);

extern "C" long pseudo_delqdisc(volatile long handle);
extern "C" long pseudo_delclass(volatile long handle);

extern "C" long pseudo_sendprio(volatile long handle, volatile long count, volatile long size);

const long ROOT_ID = 0xbeaf000000ffff00;

static void reset_qdisc()
{
    __reset_qdisc();
}

extern "C" void error(char* error, int error_num)
{
    failmsg("error -> ", "%s , %d", error, error_num);
}

static void setup_qdisc()
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


#if SYZ_EXECUTOR || __NR_syz_addclass_drr

static long syz_addclass_drr(volatile long port_qdisc, volatile long class_num, volatile long opts, volatile long size)
{
    return pseudo_addclass(Q_DRR, port_qdisc, class_num, opts, size);
}
#endif

#if SYZ_EXECUTOR || __NR_syz_addclass_ets

static long syz_addclass_ets(volatile long port_qdisc, volatile long class_num, volatile long opts, volatile long size)
{
    return pseudo_addclass(Q_ETS, port_qdisc, class_num, opts, size);
}
#endif

#if SYZ_EXECUTOR || __NR_syz_addclass_hfsc

static long syz_addclass_hfsc(volatile long port_qdisc, volatile long class_num, volatile long opts, volatile long size)
{
    return pseudo_addclass(Q_HFSC, port_qdisc, class_num, opts, size);
}
#endif

#if SYZ_EXECUTOR || __NR_syz_addclass_htb

static long syz_addclass_htb(volatile long port_qdisc, volatile long class_num, volatile long opts, volatile long size)
{
    return pseudo_addclass(Q_HTB, port_qdisc, class_num, opts, size);
}
#endif

#if SYZ_EXECUTOR || __NR_syz_addclass_prio

static long syz_addclass_prio(volatile long port_qdisc, volatile long class_num, volatile long opts, volatile long size)
{
    return pseudo_addclass(Q_PRIO, port_qdisc, class_num, opts, size);
}
#endif

#if SYZ_EXECUTOR || __NR_syz_addclass_qfq

static long syz_addclass_qfq(volatile long port_qdisc, volatile long class_num, volatile long opts, volatile long size)
{
    return pseudo_addclass(Q_QFQ, port_qdisc, class_num, opts, size);
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
