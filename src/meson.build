gnome = import('gnome')

ui_resource_xml = 'UI/ui_resources.gresource.xml' 

ui_resources = gnome.compile_resources('ui_resources',
  ui_resource_xml,
  c_name: 'ui'
)

asus_5606_ctl_sources = [
  'main.cpp',
  'Commands.cpp',
  'UI/Window.cpp',
  ui_resources,
]

asus_5606_ctl_deps = [
  dependency('gtkmm-4.0'),
]

executable('asus-5606-ctl', asus_5606_ctl_sources,
  dependencies: asus_5606_ctl_deps,
  install: true,
)

