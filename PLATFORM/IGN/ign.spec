Summary:V-Kakula
Name:KAKULA
Version:1.0.0
Release:20140717
License:BSD
Group:System Environment/Base
Source0:KAKULA.zip
BuildRoot:%{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)
Requires:qt5-qtbase
BuildRequires:qt5-qtbase
BuildRequires:gcc-c++

%description
Kakula

%prep
%setup -q -n %{name}

%install
install -d -m 755 $RPM_BUILD_ROOT/usr/bin
install -d -m 755 $RPM_BUILD_ROOT/usr/lib
install -d -m 755 $RPM_BUILD_ROOT/usr/share
install -d -m 755 $RPM_BUILD_ROOT/usr/share/kakula
install -d -m 755 $RPM_BUILD_ROOT/usr/share/kakula/nuada
install -d -m 755 $RPM_BUILD_ROOT/usr/share/kakula/kontemporer

ls 
qmake-qt5
make
cp -rf kakula $RPM_BUILD_ROOT/usr/bin
cp -rf libfftreal.so* $RPM_BUILD_ROOT/usr/lib
cp -rf assets/nuada/* $RPM_BUILD_ROOT/usr/share/kakula/nuada
cp -rf assets/kontemporer/* $RPM_BUILD_ROOT/usr/share/kakula/kontemporer

%clean

%files
%defattr(-,root,root,-)
/usr/bin/kakula
/usr/lib/*
/usr/share/kakula/nuada/a1.ogg
/usr/share/kakula/nuada/a2.ogg
/usr/share/kakula/nuada/a3.ogg
/usr/share/kakula/nuada/a4.ogg
/usr/share/kakula/nuada/a5.ogg
/usr/share/kakula/nuada/a6.ogg
/usr/share/kakula/nuada/a7.ogg
/usr/share/kakula/kontemporer/a1.ogg
/usr/share/kakula/kontemporer/a2.ogg
/usr/share/kakula/kontemporer/a3.ogg
/usr/share/kakula/kontemporer/a4.ogg
/usr/share/kakula/kontemporer/a5.ogg
/usr/share/kakula/kontemporer/a6.ogg
/usr/share/kakula/kontemporer/a7.ogg
