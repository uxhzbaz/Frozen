/* Freezeit: 冻它模块
 * Copyright (c) 2023 JARK006
 * 
 * 主线程8MiB  子线程 栈深约 1016Kib
 * 
 */

#include "freezeit.hpp"
#include "settings.hpp"
#include "managedApp.hpp"
#include "systemTools.hpp"
#include "doze.hpp"
#include "freezer.hpp"
#include "server.hpp"

int main(int argc, char **argv) {

    char tmp[1024];
    string fullPath(realpath(argv[0], tmp));

    Utils::Init();

    // 使用两个参数的构造函数
    Freezeit freezeit(argc);
    Settings settings(freezeit);
    ManagedApp managedApp(freezeit, settings);
    SystemTools systemTools(freezeit, settings);
    Doze doze(freezeit, settings, managedApp, systemTools);
    Freezer freezer(freezeit, settings, managedApp, systemTools, doze);
    Server server(freezeit, settings, managedApp, systemTools, doze, freezer);

    sleep(3600 * 24 * 365); // 放年假
    return 0;
}
