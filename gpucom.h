/*
** ATOP - System & Process Monitor
**
** The program 'atop' offers the possibility to view the activity of 
** the system on system-level as well as process-level.
** ==========================================================================
** Author:      Gerlof Langeveld
** E-mail:      gerlof.langeveld@atoptool.nl
** Date:        September 2002
** --------------------------------------------------------------------------
** Copyright (C) 2000-2010 Gerlof Langeveld
**
** This program is free software; you can redistribute it and/or modify it
** under the terms of the GNU General Public License as published by the
** Free Software Foundation; either version 2, or (at your option) any
** later version.
**
** This program is distributed in the hope that it will be useful, but
** WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
** --------------------------------------------------------------------------
*/

#ifndef	__GPUCOM__
#define	__GPUCOM__

#include <nvml.h>
#include <stdint.h>

#define GPU_VENDOR_NVIDIA	'N'
#define GPU_VENDOR_AMD   	'A'

struct gpupidstat {
    long            pid;
    struct gpu      gpu;
};

/* Function prototypes */
int     gpu_init(void);
void    gpu_end(void);
int     gpu_stats_read(struct pergpu *ggs, struct gpupidstat **gps);
void    gpu_merge_proc(struct tstat *curtpres, int ntaskpres,
                     struct tstat *curpexit, int nprocexit,
                     struct gpupidstat *gpuproc, int nrgpuproc);

#endif
