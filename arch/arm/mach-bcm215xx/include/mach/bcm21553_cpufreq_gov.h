/*******************************************************************************
* Copyright 2010 Broadcom Corporation.  All rights reserved.
*
*       @file   arch/arm/mach-bcm215xx/bcm21553_cpufreq_gov.h
*
* Unless you and Broadcom execute a separate written software license agreement
* governing use of this software, this software is licensed to you under the
* terms of the GNU General Public License version 2, available at
* http://www.gnu.org/copyleft/gpl.html (the "GPL").
*
* Notwithstanding the above, under no circumstances may you combine this
* software in any way with any other Broadcom software provided under a license
* other than the GPL, without Broadcom's express prior written consent.
*******************************************************************************/
//Disabled 1124 for unstability, for samurai kernel
#ifndef BCM21553_CPUFREQ_GOV_H
#define BCM21553_CPUFREQ_GOV_H

/* List of arm core clk frequencies. this is used by bcm21553 governor, which
 * expects the frequency value to be in kHz.
 */
enum {
	BCM21553_CORECLK_KHZ_156 = (156U * 1000),
	BCM21553_CORECLK_KHZ_312 = (312U * 1000),
	BCM21553_CORECLK_KHZ_468 = (468U * 1000),
	BCM21553_CORECLK_KHZ_624 = (624U * 1000),
	BCM21553_CORECLK_KHZ_832 = (832U * 1000),
	BCM21553_CORECLK_KHZ_936 = (936U * 1000),
//	BCM21553_CORECLK_KHZ_1124 = (1124U * 1000),
};

struct bcm21553_cpufreq_gov_plat {
	unsigned int freq_turbob;
	unsigned int freq_turboa;
	unsigned int freq_turbo;
	unsigned int freq_medb;
	unsigned int freq_meda;
	unsigned int freq_normal;
	unsigned int freq_lowa;
};

/* helper for cpufreq_bcm_client_get */
#define cpufreq_bcm_client_get(name)   \
	_cpufreq_bcm_client_get(name, THIS_MODULE)

#if defined(CONFIG_CPU_FREQ)
/* Returns the client id */
extern struct cpufreq_client_desc *_cpufreq_bcm_client_get(const char *name,
						   struct module *owner);
extern void cpufreq_bcm_client_put(struct cpufreq_client_desc *desc);

/* Pass the client id obtained from the client_get function
 * to the following APIs
 */
extern void cpufreq_bcm_dvfs_enable(struct cpufreq_client_desc *desc);
extern void cpufreq_bcm_dvfs_disable(struct cpufreq_client_desc *desc);
#else

#define _cpufreq_bcm_client_get(name, owner) NULL
#define cpufreq_bcm_client_put(desc)
#define cpufreq_bcm_dvfs_enable(desc)
#define cpufreq_bcm_dvfs_disable(desc)

#endif

#endif /* BCM21553_CPUFREQ_GOV_H */
