#pragma once

#include "gtkmm-4.0/gtkmm.h"

class Window : public Gtk::ApplicationWindow {
    public:
        Window();

    protected:
        void on_set_fan_state_0_button_clicked();
        void on_set_fan_state_1_button_clicked();
        void on_set_fan_state_2_button_clicked();
        void on_set_fan_state_3_button_clicked();
        void on_about_button_clicked();

        void update_fan_status();

        Gtk::Label* fan_status_label = nullptr;
        Gtk::Button* set_fan_state_0_button = nullptr;
        Gtk::Button* set_fan_state_1_button = nullptr;
        Gtk::Button* set_fan_state_2_button = nullptr;
        Gtk::Button* set_fan_state_3_button = nullptr;
};