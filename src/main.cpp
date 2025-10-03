#include "UI/Window.h"
#include <gtkmm-4.0/gtkmm.h>

extern "C" {
    GResource *ui_get_resource(void);
}

int main(int argc, char* argv[]) {
    auto resource = Glib::wrap(ui_get_resource());
    resource->register_global();
    
    auto app = Gtk::Application::create("dev.heggo.Asus5606ctl");
    return app->make_window_and_run<Window>(argc, argv);
}
