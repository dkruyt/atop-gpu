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
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define GPU_VENDOR_NVIDIA	'N'
#define GPU_VENDOR_AMD   	'A'

#define GPUDPORT    59123
#define DUMMY       ' '
#define GPUDELIM    '@'
#define PIDDELIM    '#'
#define APIVERSION  2

struct gpupidstat {
    long            pid;
    struct gpu      gpu;
};

/* Function prototypes */
int     gpud_init(void);
int     gpud_statrequest(void);
int     gpud_statresponse(int maxgpu, struct pergpu *ggs, struct gpupidstat **gps);
void    gpumergeproc(struct tstat *curtpres, int ntaskpres,
                     struct tstat *curpexit, int nprocexit,
                     struct gpupidstat *gpuproc, int nrgpuproc);

/* Static function prototypes */
static int  rcvuntil(int sock, char *buf, int size);
static void gputype_parse(char *buf);
static void gpustat_parse(int version, char *buf, int maxgpu,
                         struct pergpu *gg, struct gpupidstat *gp);
static void gpuparse(int version, char *p, struct pergpu *gg);
static void pidparse(int version, char *p, struct gpupidstat *gp);

/* Global variables */
extern int actsock;
extern int numgpus;
extern char **gpubusid;
extern char **gputypes;
extern char *gputasks;

#endif
