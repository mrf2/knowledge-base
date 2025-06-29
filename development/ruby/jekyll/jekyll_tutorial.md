# Jekyll Step by Step Tutorial
---
## 1. Setup

### Installation
Jekyll is a Ruby gem. ***At first, we have to install Ruby on our machine***
 * Install Ruby and other prerequisite:
```vim
sudo apt install ruby-full build-essential zlib1g-dev
```
Aoid installing RubyGems package (called gems) as the root user. Instead, set up a gem installation directory for the user account. The following commands will add environment variables to our `~/.bashrc` file to configure the gem installation path:
```vim
echo `# Install Ruby Gems to ~/gems' >> ~/.bashrc
echo 'export GEM_HOME="$HOME/gems"' >> ~/.bashrc
echo 'export PATH="$HOME/gems/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc
```
 * Install **Jekyll** from the termival
```vim
gem install jekyll bundler
```
