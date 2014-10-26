% from wikipedia
% article about superformula

function sf2d(n,a)
    u=[0:.001:2*pi+0.03];
    raux=abs(1/a(1).*abs(cos(n(1)*u/4))).^n(3)+abs(1/a(2).*abs(sin(n(1)*u/4))).^n(4);
    r=abs(raux).^(-1/n(2));
    x=r.*cos(u);
    y=r.*sin(u);
    plot(x,y);
  end

