import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class UrlService {

  private BASE_URL = 'https://fmr-api-14234341.appspot.com';
  //private BASE_URL = 'http://localhost:8080';

  constructor() { }

  public baseUrl() {
    return this.BASE_URL;
  }
}
