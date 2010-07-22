/*
  Copyright (C) 2006, 2007, 2008, 2009, 2010  Anthony Catel <a.catel@weelya.com>

  This file is part of APE Server.
  APE is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  APE is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with APE ; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

/* log.h */

#ifndef _LOG_H
#define _LOG_H

#include "main.h"

typedef enum {
	APE_DEBUG 	= 0x01,
	APE_WARN        = 0x02,
	APE_ERR         = 0x04,
	APE_INFO        = 0x08
} ape_log_lvl_t;

void ape_log_init(acetables *g_ape);
void ape_log(ape_log_lvl_t lvl, const char *file, unsigned long int line, acetables *g_ape, char *buf, ...);

extern acetables *log_g_ape;

#define _ape_log(lvl, fmt, args...)	\
  do {									\
    ape_log(lvl, __FILE__, __LINE__, log_g_ape, fmt, ##args);		\
  } while(0)								\

#define dbg(fmt, args...)			\
  _ape_log(APE_DEBUG, fmt, ##args)

#define info(fmt, args...)			\
  _ape_log(APE_DEBUG, fmt, ##args)

#define warn(fmt, args...)			\
  _ape_log(APE_DEBUG, fmt, ##args)

#define err(fmt, args...)			\
  _ape_log(APE_DEBUG, fmt, ##args)

#endif
