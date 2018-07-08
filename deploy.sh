xrandr --size 1680x1050

# wget https://github.com/davidzwa/gr-ieee802-11ah/raw/dynamic-ofdm-alloc/deploy.sh; bash deploy.sh
sudo apt-get update
cd /home/ubuntu/Documents
mkdir repos
cd repos
git clone https://github.com/davidzwa/gr-ieee802-11ah
cd gr-ieee802-11ah
git config --global user.email "davidzwa@gmail.com"
git config --global user.name "AutoDeployer"
git checkout dynamic-ofdm-alloc
sh maker.sh
cd ..	# out of gr-ieee802-11ah to Documents

git clone https://github.com/bastibl/gr-foo
cp gr-ieee802-11ah/maker.sh gr-foo/
cd gr-foo
git checkout master
sh maker.sh
cd .. # out of gr-foo
cd .. # out of repos

cp -a repos/gr-ieee802-11ah/examples/. ./

gnome-open wifi_corr_hier.grc
gnome-open wifi_phy_hier.grc
gnome-open 802.11ah_txrx_restructure.grc

wget -qO - https://download.sublimetext.com/sublimehq-pub.gpg | sudo apt-key add -
sudo apt-get install apt-transport-https
echo "deb https://download.sublimetext.com/ apt/stable/" | sudo tee /etc/apt/sources.list.d/sublime-text.list
sudo apt-get update
sudo apt-get install sublime-text


# Assumes sublime project was opened
subl --project gr-ah.sublime-project
