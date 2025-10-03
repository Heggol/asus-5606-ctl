#include "Window.h"
#include "../Commands.h"
#include <iostream>

Window::Window() {
    set_title("Asus 5606 Control");
    set_default_size(400, 300);

    auto builder = Gtk::Builder::create_from_resource("/dev/heggo/Asus5606ctl/UI/main.ui");
    auto main_box = builder->get_widget<Gtk::Box>("main_box");
    set_child(*main_box);

    fan_status_label = builder->get_widget<Gtk::Label>("fan_status_label");
    set_fan_state_0_button = builder->get_widget<Gtk::Button>("set_fan_state_0_button");
    set_fan_state_1_button = builder->get_widget<Gtk::Button>("set_fan_state_1_button");
    set_fan_state_2_button = builder->get_widget<Gtk::Button>("set_fan_state_2_button");
    set_fan_state_3_button = builder->get_widget<Gtk::Button>("set_fan_state_3_button");

    set_fan_state_0_button->signal_clicked().connect(sigc::mem_fun(*this, &Window::on_set_fan_state_0_button_clicked));
    set_fan_state_1_button->signal_clicked().connect(sigc::mem_fun(*this, &Window::on_set_fan_state_1_button_clicked));
    set_fan_state_2_button->signal_clicked().connect(sigc::mem_fun(*this, &Window::on_set_fan_state_2_button_clicked));
    set_fan_state_3_button->signal_clicked().connect(sigc::mem_fun(*this, &Window::on_set_fan_state_3_button_clicked));

    auto about_button = Gtk::make_managed<Gtk::Button>();
    about_button->set_icon_name("help-about-symbolic");
    about_button->signal_clicked().connect(sigc::mem_fun(*this, &Window::on_about_button_clicked));
    auto header = Gtk::make_managed<Gtk::HeaderBar>();
    header->pack_end(*about_button);
    set_titlebar(*header);


    update_fan_status();
}

void Window::on_set_fan_state_0_button_clicked() {
    set_fan_state(0);
    update_fan_status();
}

void Window::on_set_fan_state_1_button_clicked() {
    set_fan_state(1);
    update_fan_status();
}

void Window::on_set_fan_state_2_button_clicked() {
    set_fan_state(2);
    update_fan_status();
}

void Window::on_set_fan_state_3_button_clicked() {
    set_fan_state(3);
    update_fan_status();
}

void Window::on_about_button_clicked() {
    auto dialog = Gtk::make_managed<Gtk::AboutDialog>();
    dialog->set_program_name("Asus 5606 Control");
    dialog->set_version("0.0.1");
    dialog->set_copyright("Copyright (C) 2025");
    dialog->set_license_type(Gtk::License::GPL_3_0);
    dialog->set_website("https://github.com/Heggol/asus-5606-ctl");
    dialog->set_transient_for(*this);
    dialog->set_modal(true);
    dialog->show();
}

void Window::update_fan_status() {
    std::string fan_state = get_fan_state();
    fan_status_label->set_text("Fan Status: " + fan_state);
}