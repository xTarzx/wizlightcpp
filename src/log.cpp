/***************************************************************************
 *  Project                WIZLIGHTCPP
 *
 * Copyright (C) 2022 , Sri Balaji S.
 *
 * This software is licensed as described in the file LICENSE, which
 * you should have received as part of this distribution.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the LICENSE file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 * @file log.cpp
 *
 ***************************************************************************/

#include <sys/time.h>
#include <unistd.h>
#include <sstream>
#include <iomanip>
#include <stdarg.h>
#include <stdio.h>
#include "log.h"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#else
#include <sys/syscall.h>
#endif
// using namespace std;
using std::string;

namespace L
{
        std::map<LEVEL, string> m_lmap{
            {f, "FATAL"}, {e, "ERROR"}, {w, "WARN"}, {i, "INFO"}, {d, "DEBUG"}};
        LEVEL g_level = L::i;

        void setLogLevel(LEVEL level)
        {
                g_level = level;
        }

        string getCurrTime()
        {
                struct timeval curTime;
                char tStamp[50] = {}, ms[5] = {};
                std::stringstream sstime;

                gettimeofday(&curTime, NULL);
#ifdef _WIN32
                strftime(tStamp, sizeof(tStamp), "%Y-%m-%d %H:%M:%S", localtime((time_t *)&curTime.tv_sec));
#else
                strftime(tStamp, sizeof(tStamp), "%F %T", localtime(&curTime.tv_sec));
#endif
                snprintf(ms, 5, ".%03u", (int)curTime.tv_usec / 1000);
                sstime << tStamp << ms;
                return sstime.str();
        }

        string getLogPrefix(LEVEL level)
        {
                string lvl = m_lmap.at(level);
                string time = getCurrTime();
                std::ostringstream ostrout;

#ifdef __GLIBC__
                pid_t t_id = syscall(__NR_gettid);
                ostrout << time << " " << program_invocation_short_name;
#else
                pid_t t_id = getpid();
#ifdef _WIN32
                LPSTR path{};
                GetModuleFileName(0, path, MAX_PATH);
                ostrout << time << " " << path;
#else
                ostrout << time << " " << getprogname();
#endif
#endif
                ostrout << "(" << std::to_string(t_id) << ") ";
                ostrout << lvl.c_str() << "\t: ";
                return ostrout.str();
        }

        void log(LEVEL lvl, const char *format, ...)
        {
                if (lvl > g_level)
                        return;

                string mesg = getLogPrefix(lvl);
                va_list argptr;

                va_start(argptr, format);
                fprintf(stdout, "%s", mesg.c_str());
                vfprintf(stdout, format, argptr);
                fprintf(stdout, "\n");
                va_end(argptr);
        }
}
