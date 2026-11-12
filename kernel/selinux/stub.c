#include <linux/types.h>
#include <linux/cred.h>
#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/version.h>

#include "selinux/selinux.h"
#include "feature/selinux_hide.h"

/*
 * Used when the kernel is older than 5.8, where the SELinux policy API that
 * selinux/*.c and feature/selinux_hide.c rely on (selinux_state.policy, RCU
 * policy access, filename_trans_key) does not exist. Every entry point keeps
 * the same signature and returns the no-op / negative value of the real one.
 */

void setup_selinux(const char *domain, struct cred *cred)
{
}

void setenforce(bool enforce)
{
}

bool getenforce(void)
{
    return true;
}

void cache_sid(void)
{
}

bool is_task_ksu_domain(const struct cred *cred)
{
    return false;
}

bool is_ksu_domain(void)
{
    return false;
}

bool is_zygote(const struct cred *cred)
{
    return false;
}

bool is_init(const struct cred *cred)
{
    return false;
}

bool is_adbd(const struct cred *cred)
{
    return false;
}

void apply_kernelsu_rules(void)
{
}

int handle_sepolicy(void __user *user_data, u64 data_len)
{
    return -EOPNOTSUPP;
}

void setup_ksu_cred(void)
{
}

void escape_to_root_for_adb_root(void)
{
}

struct inode_security_struct *ksu_selinux_inode(const struct inode *inode)
{
    return NULL;
}

#if defined(MODULE) && defined(CONFIG_DEBUG_INFO_BTF)
int __init ksu_selinux_inode_init(void)
{
    return 0;
}
#endif

/* 0 makes do_get_wrapper_fd() fail with -EINVAL, so the wrapper-fd feature is unavailable. */
u32 ksu_file_sid __read_mostly = 0;

/* Referenced by the SUSFS SELinux hooks; with no policy API they never match a real SID. */
u32 susfs_ksu_sid __read_mostly = 0;
u32 susfs_priv_app_sid __read_mostly = 0;

/* feature/selinux_hide.c is not built on this path (see kernel/Kbuild). */
int my_setprocattr(const char *name, void *value, size_t size)
{
    return -EOPNOTSUPP;
}

u32 susfs_zygote_sid __read_mostly = 0;
u32 susfs_zygote_next_sid __read_mostly = 0;

#ifdef CONFIG_KSU_SUSFS
bool susfs_is_sid_equal(const struct cred *cred, u32 sid2)
{
    return false;
}

u32 susfs_get_sid_from_name(const char *secctx_name)
{
    return 0;
}

u32 susfs_get_current_sid(void)
{
    return 0;
}

void susfs_set_batch_sid(void)
{
}

bool susfs_is_current_zygote_domain(void)
{
    return false;
}

bool susfs_is_current_zygote_next_domain(void)
{
    return false;
}

bool susfs_is_current_ksu_domain(void)
{
    return false;
}

bool susfs_is_current_init_domain(void)
{
    return false;
}
#endif

bool ksu_selinux_hide_enabled __read_mostly = false;
bool ksu_selinux_hide_running __read_mostly = false;

void ksu_selinux_hide_init(void)
{
}

void ksu_selinux_hide_exit(void)
{
}

void ksu_selinux_hide_drop_backup_if_unused(void)
{
}

void ksu_selinux_hide_handle_second_stage(void)
{
}

void ksu_selinux_hide_handle_post_fs_data(void)
{
}
