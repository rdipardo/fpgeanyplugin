window.addEventListener('DOMContentLoaded', function() {
  try {
    var ico = document.createElement('link')
    ico.rel = 'icon'
    ico.type = 'image/x-icon'
    ico.href = ((location.hostname.toLowerCase().indexOf('github') > -1)
      ? '/' + location.pathname.split('/').slice(1,2).concat('favicon.ico').join('/')
      : location.protocol + '//' + location.host + '/favicon.ico')
    document.head.appendChild(ico)
  } catch (e) {
      console.info(e.constructor.name + ':', e.message);
  }
});
