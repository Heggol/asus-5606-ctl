project('asus-5606-ctl', ['cpp', 'c'],
          version: '0.0.1',
    meson_version: '>= 1.0.0',
  default_options: [ 'warning_level=2', 'werror=false', 'cpp_std=gnu++2a', ],
)

# Install polkit policy
install_data(
  'dev.heggo.Asus5606ctl.policy',
  install_dir: join_paths(get_option('datadir'), 'polkit-1', 'actions')
)

subdir('src')

